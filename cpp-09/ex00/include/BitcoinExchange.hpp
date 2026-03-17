/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:54:40 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/17 06:01:05 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <ctime>
#include <exception>
#include <map>
#include <string>

#define PARSING_ERROR_MSG "Error: Parsing File Error"
#define NO_SEPARATOR_ERROR_MSG "Error: No Separator Found"
#define DATE_ERROR_MSG "Error: Invalid Date"
#define INVALID_NUMBER_MSG "Error: Invalid Number"

#define TOO_LOW_VALUE_ERROR_MSG "Error: Too Low Value"
#define TOO_LARGE_VALUE_ERROR_MSG "Error: Too Large Value"
#define TOO_LARGE_DATE_ERROR_MSG "Error: Too Large Date"
#define TOO_LOW_DATE_ERROR_MSG "Error: Too Low Date"

#define PAIR_KEY_ERROR 0
#define DATA_FILE "data/data.csv"
#define BTC_MIN 0
#define BTC_MAX 1000

enum ErrorType { TOO_LOW_DATE = -1, TOO_LARGE_DATE = -2 };

namespace btcdata {
std::pair<std::time_t, double> parseAndValidateLine(std::string line,
                                                    char separator);
std::map<std::time_t, double> parseFileContent(const char *filename,
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
std::time_t dateStrToTimestamp(std::string date);
std::string timestampToDateStr(std::time_t timestamp);
bool isValidNumber(std::string value);
bool isValidDate(std::string dateStr, std::time_t timestamp);
}  // namespace btcutils

namespace btc {
std::pair<std::time_t, double> getExchangeValueByDate(
    std::map<std::time_t, double> db, std::time_t date);
}

#endif