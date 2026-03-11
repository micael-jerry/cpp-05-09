/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:14:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/11 06:14:35 by mfidimal         ###   ########.fr       */
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
  std::map<std::string, double> data =
      btcdata::parseFileContent(DATA_FILE, ',');
  std::map<std::string, double> btcValue =
      btcdata::parseFileContent(argv[1], '|');

  std::cout << "DATA: " << std::endl;
  for (std::map<std::string, double>::iterator it = data.begin();
       it != data.end(); it++) {
    std::cout << it->first << " => " << it->second << std::endl;
  }

  std::cout << std::endl << "BTC VALUE: " << std::endl;
  for (std::map<std::string, double>::iterator it = btcValue.begin();
       it != btcValue.end(); it++) {
    std::cout << it->first << " => " << it->second << std::endl;
  }
  return 0;
}
