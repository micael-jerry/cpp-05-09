/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:14:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/16 06:20:16 by mfidimal         ###   ########.fr       */
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
    std::pair<std::time_t, double> exchange = btc::getExchangeValueByDate(db, it->first);
    std::cout << btcutils::timestampToDateStr(it->first) << " => " << it->second << " = " << it->second * exchange.second << std::endl;
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
        btcdata::parseFileContent(argv[1], '|', true);

    view(db, input);
  } catch (btcdata::parseException &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
