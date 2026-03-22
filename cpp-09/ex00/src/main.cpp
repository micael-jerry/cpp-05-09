/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:14:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/22 09:14:15 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <utility>

#include "../include/BitcoinExchange.hpp"

void view(std::pair<std::time_t, double> pair,
          std::map<std::time_t, double> db) {
  if (pair.second < BTC_MIN) {
    throw btc::btcException(TOO_LOW_VALUE_ERROR_MSG);
  }
  if (pair.second > BTC_MAX) {
    throw btc::btcException(TOO_LARGE_VALUE_ERROR_MSG);
  }

  std::pair<std::time_t, double> exchange =
      btc::getExchangeValueByDate(db, pair.first);

  std::cout << btcutils::timestampToDateStr(exchange.first) << " => "
            << pair.second << " = " << exchange.second * pair.second
            << std::endl;
}

void convert(const char *filename, std::map<std::time_t, double> db) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw btcdata::parseException(PARSING_ERROR_MSG);
  }

  std::string line;
  std::getline(file, line);  // INFO: REMOVE HEADERS
  while (std::getline(file, line)) {
    try {
      const std::pair<std::time_t, double> parsedLine =
          btcdata::parseAndValidateLine(line, INPUT_KEY_VAL_SEPARATOR);
      view(parsedLine, db);
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  file.close();
}

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cerr << "Invalid args" << std::endl;
    return 1;
  }
  try {
    std::map<std::time_t, double> db = btcdata::parseFileDb(DATA_FILE);
    convert(argv[1], db);
  } catch (btcdata::parseException &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
