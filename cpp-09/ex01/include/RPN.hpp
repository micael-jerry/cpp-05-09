/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:35:55 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/24 05:01:22 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <string>

#define MATH_OPERATION "+-/*"

namespace validator {
void isValidRPN(const std::string &params);

class ValidatorException : public std::exception {
 public:
  ValidatorException(const std::string &msg) : _msg("RPN ERROR: " + msg) {}
  virtual ~ValidatorException() throw() {}
  virtual const char *what() const throw() { return _msg.c_str(); }

 private:
  std::string _msg;
};
}  // namespace validator

#endif