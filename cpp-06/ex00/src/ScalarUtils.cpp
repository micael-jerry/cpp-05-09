/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 05:41:10 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/28 07:43:06 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarUtils.hpp"

#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

static bool isScalarChar(std::string const &str) {
  if (str.length() == 1 && !std::isdigit(str[0])) {
    return true;
  }
  return false;
}

static bool isScalarInt(std::string const &str) {
  int i = 0;
  if ((str[i] == '-' || str[i] == '+') && str.length() == 1) {
    return false;
  } else if ((str[i] == '-' || str[i] == '+') && str.length() > 1) {
    i++;
  }

  for (size_t j = i; j < str.length(); j++) {
    if (!std::isdigit(str[j])) {
      return false;
    }
  }

  const long value = std::strtol(str.c_str(), NULL, 10);
  if (value < INT_MIN || value > INT_MAX) {
    return false;
  }

  return true;
}

static bool isScalarFloat(std::string const &str) {
  int dotCount = 0;
  int fCount = 0;
  size_t i = 0;

  if (str == "f" || str == ".f" || str == "+.f" || str == "-.f") {
    return false;
  }
  if ((str[i] == '-' || str[i] == '+') && str.length() < 3) {
    return false;
  } else if ((str[i] == '-' || str[i] == '+') && str.length() >= 3) {
    i++;
  }

  if (str[str.length() - 1] != 'f') {
    return false;
  }

  for (size_t j = i; j < str.length(); j++) {
    if (str[j] == '.') {
      dotCount++;
    } else if (str[j] == 'f') {
      fCount++;
    } else if (!std::isdigit(str[j])) {
      return false;
    }
  }

  if (dotCount > 1 || fCount > 1) {
    return false;
  }

  return true;
}

static bool isScalarDouble(std::string const &str) {
  int dotCount = 0;
  size_t i = 0;

  if ((str[i] == '-' || str[i] == '+') && str.length() == 1) {
    return false;
  } else if ((str[i] == '-' || str[i] == '+') && str.length() > 1) {
    i++;
  }

  if (str[i] == '.') {
    return false;
  }

  for (size_t j = i; j < str.length(); j++) {
    if (str[j] == '.') {
      dotCount++;
    } else if (!std::isdigit(str[j])) {
      return false;
    }
  }

  if (dotCount > 1) {
    return false;
  }

  return true;
}

ScalarUtils::ScalarType ScalarUtils::detectScalarType(std::string const &str) {
  if (str.empty()) {
    return SCALAR_INVALID;
  }
  if (isScalarChar(str)) {
    return SCALAR_CHAR;
  }
  if (isScalarInt(str)) {
    return SCALAR_INT;
  }
  if (isScalarFloat(str)) {
    return SCALAR_FLOAT;
  }
  if (isScalarDouble(str)) {
    return SCALAR_DOUBLE;
  }
  return SCALAR_INVALID;
}

void ScalarUtils::printScalarValues(std::string const &str) {
  ScalarType type = detectScalarType(str);

  switch (type) {
    case SCALAR_CHAR:
      std::cout << "char: " << str << std::endl;
      break;
    case SCALAR_INT:
      std::cout << "int: " << str << std::endl;
      break;
    case SCALAR_FLOAT:
      std::cout << "float: " << str << std::endl;
      break;
    case SCALAR_DOUBLE:
      std::cout << "double: " << str << std::endl;
      break;
    default:
      std::cout << "Invalid input" << std::endl;
      break;
  }
}
