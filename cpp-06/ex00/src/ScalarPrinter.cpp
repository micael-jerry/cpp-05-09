/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarPrinter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 04:38:50 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/07 21:28:43 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarPrinter.hpp"

#include <cctype>
#include <cfloat>
#include <climits>
#include <iostream>
#include <ostream>
#include <string>

void ScalarPrinter::printCharBase(char const &chr) {
  std::cout << "char: " << chr << std::endl
            << "int: " << static_cast<int>(chr) << std::endl
            << "float: " << static_cast<float>(chr) << ".0f" << std::endl
            << "double: " << static_cast<double>(chr) << ".0" << std::endl;
}

void ScalarPrinter::printIntBase(int const &integer) {
  std::cout << "char: "
            << ((integer < CHAR_MIN || integer > CHAR_MAX) ? "impossible"
                : std::isprint(integer)
                    ? std::string(1, static_cast<char>(integer))
                    : "Non displayable")
            << std::endl
            << "int: " << integer << std::endl
            << "float: " << static_cast<float>(integer) << ".0f" << std::endl
            << "double: " << static_cast<double>(integer) << ".0" << std::endl;
}

void ScalarPrinter::printFloatBase(float const &flt) {
  std::cout << "char: "
            << ((flt < CHAR_MIN || flt > CHAR_MAX) ? "impossible"
                : std::isprint(flt) ? std::string(1, static_cast<char>(flt))
                                    : "Non displayable")
            << std::endl
            << "int: " << static_cast<int>(flt) << std::endl
            << "float: " << flt << "f" << std::endl
            << "double: " << static_cast<double>(flt) << std::endl;
}

void ScalarPrinter::printDoubleBase(double const &dbl) {
  std::cout << "char: ";
  if (dbl < CHAR_MIN || dbl > CHAR_MAX) {
    std::cout << "impossible";
  } else if (std::isprint(static_cast<int>(dbl))) {
    std::cout << static_cast<char>(dbl);
  } else {
    std::cout << "Non displayable";
  }
  std::cout << std::endl;

  std::cout << "int: ";
  if (dbl < INT_MIN || dbl > INT_MAX) {
    std::cout << "impossible";
  } else {
    std::cout << static_cast<int>(dbl);
  }
  std::cout << std::endl;

  std::cout << "float: " << static_cast<float>(dbl) << "f" << std::endl;
  if (dbl < FLT_MIN || dbl > FLT_MAX) {
    std::cout << "impossible";
  } else {
    std::cout << static_cast<float>(dbl) << "f";
  }
  std::cout << std::endl;

  std::cout << "double: " << dbl << std::endl;
}

void ScalarPrinter::printInvalidBase() {
  std::cout << "char: " << "impossible" << std::endl
            << "int: " << "impossible" << std::endl
            << "float: " << "impossible" << std::endl
            << "double: " << "impossible" << std::endl;
}
