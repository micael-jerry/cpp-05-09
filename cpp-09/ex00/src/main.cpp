/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:14:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/10 06:32:43 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>

#include "../include/BitcoinExchange.hpp"

#define DATA_FILE "data/data.csv"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cerr << "Invalid args" << std::endl;
    return 1;
  }
  (void)argv;
  std::map<std::string, double> data =
      btcdata::parseFileContentToData(DATA_FILE);

  for (std::map<std::string, double>::iterator it = data.begin();
       it != data.end(); it++) {
    std::cout << it->first << " => " << it->second << std::endl;
  }
  return 0;
}
