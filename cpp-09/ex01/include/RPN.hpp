/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:35:55 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/25 05:45:59 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <string>

#define MATH_OPERATION "+-/*"

namespace rpn {
void rpnParamsValidator(const std::string &params);
int rpn(const std::string &tokens);
int rpnOperation(int firstOperand, int secondOperand, char operation);

class RPNException : public std::exception {
 public:
  RPNException(const std::string &msg) : _msg("ERROR: " + msg) {}
  virtual ~RPNException() throw() {}
  virtual const char *what() const throw() { return _msg.c_str(); }

 private:
  std::string _msg;
};
}  // namespace rpn

#endif