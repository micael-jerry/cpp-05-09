/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarPrinter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 04:38:50 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/17 20:48:07 by mfidimal         ###   ########.fr       */
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
  std::cout << "char: ";
  if (std::isprint(chr)) {
    std::cout << "'" << chr << "'";
  } else {
    std::cout << "Non displayable";
  }
  std::cout << std::endl;

  std::cout << "int: " << static_cast<int>(chr) << std::endl
            << "float: " << static_cast<float>(chr) << ".0f" << std::endl
            << "double: " << static_cast<double>(chr) << ".0" << std::endl;
}

void ScalarPrinter::printIntBase(int const &integer) {
  std::cout << "char: ";
  if (integer < CHAR_MIN || integer > CHAR_MAX) {
    std::cout << "impossible";
  } else if (std::isprint(integer)) {
    std::cout << "'" << static_cast<char>(integer) << "'";
  } else {
    std::cout << "Non displayable";
  }
  std::cout << std::endl;

  std::cout << "int: " << integer << std::endl
            << "float: " << static_cast<float>(integer) << ".0f" << std::endl
            << "double: " << static_cast<double>(integer) << ".0" << std::endl;
}

void ScalarPrinter::printFloatBase(float const &flt) {
  std::cout << "char: ";
  if (flt < CHAR_MIN || flt > CHAR_MAX) {
    std::cout << "impossible";
  } else if (std::isprint(flt)) {
    std::cout << "'" << static_cast<char>(flt) << "'";
  } else {
    std::cout << "Non displayable";
  }
  std::cout << std::endl;

  std::cout << "int: " << static_cast<int>(flt) << std::endl;
  std::cout << "float: " << flt << (static_cast<int>(flt) == flt ? ".0f" : "f")
            << std::endl;
  std::cout << "double: " << static_cast<double>(flt)
            << (static_cast<int>(flt) == flt ? ".0" : "") << std::endl;
}

void ScalarPrinter::printDoubleBase(double const &dbl) {
  std::cout << "char: ";
  if (dbl < CHAR_MIN || dbl > CHAR_MAX) {
    std::cout << "impossible";
  } else if (std::isprint(dbl)) {
    std::cout << "'" << static_cast<char>(dbl) << "'";
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

  std::cout << "float: ";
  if (dbl < -FLT_MAX || dbl > FLT_MAX) {
    std::cout << "impossible";
  } else {
    std::cout << static_cast<float>(dbl)
              << (static_cast<int>(dbl) == dbl ? ".0f" : "f");
  }
  std::cout << std::endl;

  std::cout << "double: " << dbl << (static_cast<long>(dbl) == dbl ? ".0" : "")
            << std::endl;
}

void ScalarPrinter::printSpecialBase(const std::string &spl) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;

  if (spl == "nan" || spl == "nanf") {
    std::cout << "float: nanf" << std::endl << "double: nan" << std::endl;
  } else if (spl == "inf" || spl == "inff") {
    std::cout << "float: inff" << std::endl << "double: inf" << std::endl;
  } else if (spl == "+inf" || spl == "+inff") {
    std::cout << "float: +inff" << std::endl << "double: +inf" << std::endl;
  } else if (spl == "-inf" || spl == "-inff") {
    std::cout << "float: -inff" << std::endl << "double: -inf" << std::endl;
  }
}

void ScalarPrinter::printInvalidBase() {
  std::cout << "char: " << "impossible" << std::endl
            << "int: " << "impossible" << std::endl
            << "float: " << "impossible" << std::endl
            << "double: " << "impossible" << std::endl;
}
