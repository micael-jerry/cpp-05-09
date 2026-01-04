/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarPrinter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 04:38:50 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/04 06:27:57 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarPrinter.hpp"

#include <cctype>
#include <climits>
#include <iostream>

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
  (void) flt;
}

void ScalarPrinter::printDoubleBase(double const &dbl) {
  (void) dbl;
}

void ScalarPrinter::printInvalidBase() {
  std::cout << "char: " << "impossible" << std::endl
            << "int: " << "impossible" << std::endl
            << "float: " << "impossible" << std::endl
            << "double: " << "impossible" << std::endl;
}
