/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:26:57 by mfidimal          #+#    #+#             */
/*   Updated: 2026/04/17 20:44:04 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <iterator>

std::string btcutils::trim(const std::string &str) {
  size_t start = 0;
  size_t end = str.size();
  while (start < end && std::isspace(str[start])) ++start;
  while (end > start && std::isspace(str[end - 1])) --end;
  return str.substr(start, end - start);
}

std::time_t btcutils::dateStrToTimestamp(std::string dateStr) {
  if ((dateStr.length() != 10) || (dateStr[4] != '-' || dateStr[7] != '-')) {
    return -1;
  }

  int year, month, day;
  std::istringstream ssYear(dateStr.substr(0, 4));
  std::istringstream ssMonth(dateStr.substr(5, 2));
  std::istringstream ssDay(dateStr.substr(8, 2));

  if (!(ssYear >> year) || !(ssMonth >> month) || !(ssDay >> day)) {
    return -1;
  }

  std::tm tm = std::tm();
  tm.tm_year = year - 1900;
  tm.tm_mon = month - 1;
  tm.tm_mday = day;

  return mktime(&tm);
}

std::string btcutils::timestampToDateStr(std::time_t timestamp) {
  char buffer[11];
  std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&timestamp));
  return std::string(buffer);
}

bool btcutils::isValidDate(std::string dateStr, std::time_t timestamp) {
  if (timestamp == -1) {
    return false;
  }

  if (timestampToDateStr(timestamp) != dateStr) {
    return false;
  }
  return true;
}

bool btcutils::isValidNumber(std::string value) {
  unsigned int commaCount = 0;

  for (size_t i = 0; i < value.size(); i++) {
    if (i == 0 && (value[i] == '-' || value[i] == '+')) {
      continue;
    } else if (!std::isdigit(value[i]) && value[i] != '.') {
      return false;
    } else if (value[i] == '.') {
      commaCount++;
    }
  }

  if (commaCount > 1) {
    return false;
  }

  return true;
}

std::pair<std::time_t, double> btcdata::parseAndValidateLine(std::string line,
                                                             char separator) {
  size_t separatorPos = line.find(separator);

  if (separatorPos == std::string::npos) {
    throw btcdata::parseException(NO_SEPARATOR_ERROR_MSG);
  }

  std::string key = btcutils::trim(line.substr(0, separatorPos));
  std::string valueStr = btcutils::trim(line.substr(separatorPos + 1));

  std::time_t timestamp = btcutils::dateStrToTimestamp(key);

  if (!btcutils::isValidDate(key, timestamp)) {
    throw btcdata::parseException(INVALID_DATE_ERROR_MSG);
  }
  if (!btcutils::isValidNumber(valueStr)) {
    throw btcdata::parseException(INVALID_VALUE_ERROR_MSG);
  }
  const double value = std::strtod(valueStr.c_str(), NULL);

  return std::make_pair(timestamp, value);
}

std::map<std::time_t, double> btcdata::parseFileDb(const char *filename) {
  std::map<std::time_t, double> data;
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw btcdata::parseException(PARSING_ERROR_MSG);
  }

  std::string line;
  std::getline(file, line);  // INFO: REMOVE HEADERS
  while (std::getline(file, line)) {
    const std::pair<std::time_t, double> parsedLine =
        btcdata::parseAndValidateLine(line, DB_KEY_VAL_SEPARATOR);
    data[parsedLine.first] = parsedLine.second;
  }
  file.close();
  return data;
}

std::pair<std::time_t, double> btc::getExchangeValueByDate(
    std::map<std::time_t, double> db, std::time_t date) {
  std::map<std::time_t, double>::iterator last = db.end();
  std::advance(last, -1);

  if (date < db.begin()->first) {
    throw btc::btcException(TOO_LOW_DATE_ERROR_MSG);
  }
  if (date > last->first) {
    return *last;
  }

  std::map<std::time_t, double>::iterator value = db.lower_bound(date);

  if (value->first != date) {
    std::advance(value, -1);
  }

  return *value;
}
