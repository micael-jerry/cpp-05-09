/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/15 20:37:27 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

#include <cstdlib>

#include "../include/ScalarPrinter.hpp"
#include "../include/ScalarTypeUtil.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &sc) { (void)sc; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &sc) {
  (void)sc;
  return *this;
}

void ScalarConverter::convert(std::string const &toConvert) {
  ScalarTypeUtil::ScalarType type = ScalarTypeUtil::detectScalarType(toConvert);
  if (type == ScalarTypeUtil::SCALAR_CHAR) {
    char chr = ScalarTypeUtil::convertToChar(toConvert);
    ScalarPrinter::printCharBase(chr);
  } else if (type == ScalarTypeUtil::SCALAR_INT) {
    int integer = ScalarTypeUtil::convertToInt(toConvert);
    ScalarPrinter::printIntBase(integer);
  } else if (type == ScalarTypeUtil::SCALAR_FLOAT) {
    float flt = ScalarTypeUtil::convertToFloat(toConvert);
    ScalarPrinter::printFloatBase(flt);
  } else if (type == ScalarTypeUtil::SCALAR_DOUBLE) {
    double dbl = ScalarTypeUtil::convertToDouble(toConvert);
    ScalarPrinter::printDoubleBase(dbl);
  } else if (type == ScalarTypeUtil::SCALAR_SPECIAL) {
    ScalarPrinter::printSpecialBase(toConvert);
  } else {
    ScalarPrinter::printInvalidBase();
  }
}
