/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:35:34 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/24 06:51:19 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

#include <cctype>
#include <cstddef>

void rpn::rpnParamsValidator(const std::string &params) {
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
        throw rpn::RPNException("Each character must be separated by a space");
      }
    } else {
      throw rpn::RPNException("Invalid character");
    }
  }
}

int rpn::rpn(const std::string &tokens) {}