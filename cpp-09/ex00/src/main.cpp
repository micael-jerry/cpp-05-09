/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:14:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/17 06:00:08 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <map>
#include <ostream>

#include "../include/BitcoinExchange.hpp"

void view(std::map<std::time_t, double> db,
          std::map<std::time_t, double> input) {
  for (std::map<std::time_t, double>::iterator it = input.begin();
       it != input.end(); it++) {
    if (it->second < BTC_MIN) {
      std::cerr << TOO_LOW_VALUE_ERROR_MSG << std::endl;
      continue;
    }
    if (it->second > BTC_MAX) {
      std::cerr << TOO_LARGE_VALUE_ERROR_MSG << std::endl;
      continue;
    }

    std::pair<std::time_t, double> exchange =
        btc::getExchangeValueByDate(db, it->first);

    if (exchange.first == PAIR_KEY_ERROR) {
      if (exchange.second == TOO_LOW_DATE) {
        std::cerr << TOO_LOW_DATE_ERROR_MSG << std::endl;
      } else if (exchange.second == TOO_LARGE_DATE) {
        std::cerr << TOO_LARGE_DATE_ERROR_MSG << std::endl;
      }
    } else {
      std::cout << btcutils::timestampToDateStr(exchange.first) << " => "
                << it->second << " = " << it->second * exchange.second
                << std::endl;
    }
  }
}

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cerr << "Invalid args" << std::endl;
    return 1;
  }
  try {
    std::map<std::time_t, double> db =
        btcdata::parseFileContent(DATA_FILE, ',');
    std::map<std::time_t, double> input =
        btcdata::parseFileContent(argv[1], '|');

    view(db, input);
  } catch (btcdata::parseException &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
