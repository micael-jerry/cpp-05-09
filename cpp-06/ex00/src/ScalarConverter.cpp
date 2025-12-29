/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:13 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/29 05:17:26 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

#include "../include/ScalarPrinter.hpp"
#include "../include/ScalarTypeUtil.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &sc) {
  (void) sc;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &sc) {
  (void) sc;
  return *this;
}

void ScalarConverter::convert(std::string const &toConvert) {
  ScalarTypeUtil::ScalarType type = ScalarTypeUtil::detectScalarType(toConvert);
  if (type == ScalarTypeUtil::SCALAR_CHAR) {
    char chr = ScalarConverter::convertToChar(toConvert);
    ScalarPrinter::printCharBase(chr);
  } else {
    ScalarPrinter::printInvalidBase();
  }
}

char ScalarConverter::convertToChar(std::string const &toConvert) {
  return toConvert.at(0);
}
