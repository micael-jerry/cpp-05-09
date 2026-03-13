/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:54:40 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/13 06:34:33 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <exception>
#include <map>
#include <string>

#define PARSING_ERROR_MSG "Error: Parsing File Error"
#define NO_SEPARATOR_ERROR_MSG "Error: No Separator Found"
#define DATE_ERROR_MSG "Error: Invalid Date"
#define VALUE_ERROR_MSG "Error: Invalid Value"

namespace btcdata {
std::pair<std::string, double> parseAndValidateLine(std::string line,
                                                    char separator);
std::map<std::string, double> parseFileContent(const char *filename,
                                               char dateAndValueSeparator);

class parseException : public std::exception {
 public:
  parseException(const char *msg) : _msg(msg){};
  virtual ~parseException() throw() {}
  virtual const char *what() const throw() { return _msg.c_str(); }

 private:
  std::string _msg;
};
}  // namespace btcdata

namespace btcutils {
std::string trim(const std::string &str);
bool isValidDateStr(std::string date);
bool isValidNumber(std::string value);
}  // namespace btcutils

#endif