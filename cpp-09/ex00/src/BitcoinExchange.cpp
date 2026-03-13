/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:26:57 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/13 06:46:12 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

std::string btcutils::trim(const std::string &str) {
  size_t start = 0;
  size_t end = str.size();
  while (start < end && std::isspace(str[start])) ++start;
  while (end > start && std::isspace(str[end - 1])) --end;
  return str.substr(start, end - start);
}

bool btcutils::isValidDateStr(std::string dateStr) {
  if ((dateStr.length() != 10) || (dateStr[4] != '-' || dateStr[7] != '-')) {
    return false;
  }

  int year, month, day;
  std::istringstream ssYear(dateStr.substr(0, 4));
  std::istringstream ssMonth(dateStr.substr(5, 2));
  std::istringstream ssDay(dateStr.substr(8, 2));

  if (!(ssYear >> year) || !(ssMonth >> month) || !(ssDay >> day)) {
    return false;
  }

  std::tm tm = std::tm();
  tm.tm_year = year - 1900;
  tm.tm_mon = month - 1;
  tm.tm_mday = day;

  std::time_t date = mktime(&tm);
  if (date == -1) {
    return false;
  }

  char buffer[11];
  std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&date));
  std::string normalizedDate(buffer);

  if (normalizedDate != dateStr) {
    return false;
  }
  return true;
}

bool btcutils::isValidNumber(std::string value) {
  (void)value;
  return true;
}

std::pair<std::string, double> btcdata::parseAndValidateLine(std::string line,
                                                             char separator) {
  size_t separatorPos = line.find(separator);

  if (separatorPos == std::string::npos) {
    throw btcdata::parseException(NO_SEPARATOR_ERROR_MSG);
  }

  std::string key = btcutils::trim(line.substr(0, separatorPos));
  std::string value = btcutils::trim(line.substr(separatorPos + 1));

  if (!btcutils::isValidDateStr(key)) {
    throw btcdata::parseException(DATE_ERROR_MSG);
  }
  if (!btcutils::isValidNumber(value)) {
    throw btcdata::parseException(VALUE_ERROR_MSG);
  }

  return std::make_pair(key, std::strtod(value.c_str(), NULL));
}

std::map<std::string, double> btcdata::parseFileContent(
    const char *filename, char dateAndValueSeparator) {
  std::map<std::string, double> data;
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw btcdata::parseException(PARSING_ERROR_MSG);
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    const std::pair<std::string, double> parsedLine =
        btcdata::parseAndValidateLine(line, dateAndValueSeparator);
    data[parsedLine.first] = parsedLine.second;
  }
  file.close();
  return data;
}
