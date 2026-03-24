/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:35:55 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/24 05:26:09 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <string>
#include <vector>

#define MATH_OPERATION "+-/*"

namespace parse {
std::vector<char> parseRPNParams(const std::string &params);

class ParseException : public std::exception {
 public:
  ParseException(const std::string &msg) : _msg("RPN ERROR: " + msg) {}
  virtual ~ParseException() throw() {}
  virtual const char *what() const throw() { return _msg.c_str(); }

 private:
  std::string _msg;
};
}  // namespace parse

#endif