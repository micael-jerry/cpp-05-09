/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:26:57 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/12 06:05:01 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <map>
#include <string>
#include <utility>

std::string btcutils::trim(const std::string &str) {
  size_t start = 0;
  size_t end = str.size();
  while (start < end && std::isspace(str[start])) ++start;
  while (end > start && std::isspace(str[end - 1])) --end;
  return str.substr(start, end - start);
}

std::pair<std::string, double> btcdata::parseAndValidateLine(std::string line,
                                                             char separator) {
  size_t separatorPos = line.find(separator);

  if (separatorPos == std::string::npos) {
    throw btcdata::parseException(NO_SEPARATOR_ERROR_MSG);
  }

  std::string key = btcutils::trim(line.substr(0, separatorPos));
  std::string value = btcutils::trim(line.substr(separatorPos + 1));

  // TODO: validate date and value before saving

  return {key, std::strtod(value.c_str(), NULL)};
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
