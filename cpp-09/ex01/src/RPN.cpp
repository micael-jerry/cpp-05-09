/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:35:34 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/24 05:26:09 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

#include <cctype>
#include <cstddef>
#include <vector>

std::vector<char> parse::parseRPNParams(const std::string &params) {
  std::string mathOperation = std::string(MATH_OPERATION);
  size_t len = params.length();
  std::vector<char> res;

  for (size_t i = 0; i < len; i++) {
    if (params[i] == ' ') {
      continue;
    }
    if (std::isdigit(params[i]) ||
        mathOperation.find(params[i]) != std::string::npos) {
      if (len > 1 && ((i > 0 && params[i - 1] != ' ') ||
                      (i < len - 1 && params[i + 1] != ' '))) {
        throw parse::ParseException(
            "Each character must be separated by a space");
      }
      res.push_back(params[i]);
    } else {
      throw parse::ParseException("Invalid character");
    }
  }
  return res;
}