/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 05:41:10 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/25 20:48:47 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarUtils.hpp"
#include <cctype>

static bool isScalarChar(std::string const &str) {
  if (str.length() == 1 && !std::isdigit(str[0])) {
    return true;
  }
  return false;
}

ScalarUtils::ScalarType ScalarUtils::detectScalarType(std::string const &str) {
  if (isScalarChar(str)) {
    return SCALAR_CHAR;
  }
  return SCALAR_INVALID;
}
