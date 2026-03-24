/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:35:34 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/24 05:11:02 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

#include <cctype>
#include <cstddef>

void validator::isValidRPN(const std::string &params) {
  std::string mathOperation = std::string(MATH_OPERATION);
  size_t len = params.length();

  for (size_t i = 0; i < len; i++) {
    if (params[i] == ' ') {
      continue;
    }
    if (std::isdigit(params[i]) ||
        mathOperation.find(params[i]) != std::string::npos) {
      if (len > 1 && ((i > 0 && params[i - 1] != ' ') ||
                      (i < len - 1 && params[i + 1] != ' '))) {
        throw validator::ValidatorException(
            "Each character must be separated by a space");
      }
    } else {
      throw validator::ValidatorException("Invalid character");
    }
  }
}