/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:14:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/13 07:02:21 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <ostream>
#include <string>

#include "../include/BitcoinExchange.hpp"

#define DATA_FILE "data/data.csv"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cerr << "Invalid args" << std::endl;
    return 1;
  }
  try {
    std::map<std::string, double> db =
        btcdata::parseFileContent(DATA_FILE, ',');
    std::map<std::string, double> input =
        btcdata::parseFileContent(argv[1], '|');

    std::cout << "DB: " << std::endl;
    for (std::map<std::string, double>::iterator it = db.begin();
         it != db.end(); it++) {
      std::cout << it->first << " => " << it->second << std::endl;
    }

    std::cout << std::endl << "INPUT: " << std::endl;
    for (std::map<std::string, double>::iterator it = input.begin();
         it != input.end(); it++) {
      std::cout << it->first << " => " << it->second << std::endl;
    }
  } catch (btcdata::parseException &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
