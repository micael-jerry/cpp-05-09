/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:35:34 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/27 06:18:15 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

#include <cctype>
#include <cstddef>
#include <stack>

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
        throw RPNException("Each character must be separated by a space");
      }
    } else {
      throw RPNException("Invalid character");
    }
  }
}

int rpn::rpn(const std::string &tokens) {
  std::string mathOperation = std::string(MATH_OPERATION);
  std::stack<int> stack;

  for (size_t i = 0; i < tokens.length(); i++) {
    if (tokens[i] == ' ') {
      continue;
    } else if (std::isdigit(tokens[i])) {
      stack.push(tokens[i] - '0');
    } else if (mathOperation.find(tokens[i]) != std::string::npos) {
      if (stack.size() < 2) {
        throw RPNException("Not enough operands");
      }
      int secondOperand = stack.top();
      stack.pop();
      int firstOperand = stack.top();
      stack.pop();
      stack.push(rpnOperation(firstOperand, secondOperand, tokens[i]));
    }
  }
  if (stack.size() != 1) {
    throw RPNException("Invalid RPN expression");
  }
  return stack.top();
}

int rpn::rpnOperation(int firstOperand, int secondOperand, char operation) {
  switch (operation) {
    case '+':
      return firstOperand + secondOperand;
    case '-':
      return firstOperand - secondOperand;
    case '/':
      if (secondOperand == 0) {
        throw RPNException("Division by zero");
      }
      return firstOperand / secondOperand;
    case '*':
      return firstOperand * secondOperand;
    default:
      throw RPNException("Invalid operation");
  }
}