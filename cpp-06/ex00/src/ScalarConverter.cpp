/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/05 06:23:12 by mfidimal         ###   ########.fr       */
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
    char chr = ScalarConverter::convertToChar(toConvert);
    ScalarPrinter::printCharBase(chr);
  } else if (type == ScalarTypeUtil::SCALAR_INT) {
    int integer = ScalarConverter::convertToInt(toConvert);
    ScalarPrinter::printIntBase(integer);
  } else if (type == ScalarTypeUtil::SCALAR_FLOAT) {
    float flt = ScalarConverter::convertToFloat(toConvert);
    ScalarPrinter::printFloatBase(flt);
  } else if (type == ScalarTypeUtil::SCALAR_DOUBLE) {
    double dbl = ScalarConverter::convertToDouble(toConvert);
    ScalarPrinter::printDoubleBase(dbl);
  } else {
    ScalarPrinter::printInvalidBase();
  }
}

char ScalarConverter::convertToChar(std::string const &toConvert) {
  return toConvert.at(0);
}

int ScalarConverter::convertToInt(std::string const &toConvert) {
  return std::strtol(toConvert.c_str(), NULL, 10);
}

float ScalarConverter::convertToFloat(std::string const &toConvert) {
  return std::strtof(toConvert.c_str(), NULL);
}

double ScalarConverter::convertToDouble(std::string const &toConvert) {
  return std::strtof(toConvert.c_str(), NULL);
}
