/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:26:57 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/11 06:10:44 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

std::map<std::string, double> btcdata::parseFileContent(const char *filename, char dateAndValueSeparator) {
  std::map<std::string, double> data;
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Error: could not open file" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    const std::string key = line.substr(0, line.find(dateAndValueSeparator));
    const std::string value = line.substr(line.find(dateAndValueSeparator) + 1);
    data[key] = std::strtod(value.c_str(), NULL);
  }
  file.close();
  return data;
}
