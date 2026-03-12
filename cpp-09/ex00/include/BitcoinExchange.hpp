/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:54:40 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/12 05:44:39 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <exception>
#include <map>
#include <string>

#define PARSING_ERROR_MSG "Error: Parsing File Error"
#define NO_SEPARATOR_ERROR_MSG "Error: No Separator Found"

namespace btcdata {
std::pair<std::string, double> parseAndValidateLine(std::string line,
                                                    char separator);
std::map<std::string, double> parseFileContent(const char *filename,
                                               char dateAndValueSeparator);

class parseException : public std::exception {
 public:
  parseException(const char *msg) : _msg(msg){};
  virtual const char *what() const noexcept override { return _msg.c_str(); }

 private:
  std::string _msg;
};
}  // namespace btcdata

namespace btcutils {
std::string trim(const std::string &str);
bool isValidDate(std::string date);
bool isValidValue(std::string value);
}  // namespace btcutils

#endif