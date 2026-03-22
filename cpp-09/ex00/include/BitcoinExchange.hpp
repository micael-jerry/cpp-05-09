/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:54:40 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/22 07:43:58 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <ctime>
#include <exception>
#include <map>
#include <string>

#define PARSING_ERROR_MSG "Parsing File Error"
#define NO_SEPARATOR_ERROR_MSG "No Separator Found"
#define INVALID_DATE_ERROR_MSG "Invalid Date"
#define INVALID_VALUE_ERROR_MSG "Invalid Value"

#define TOO_LOW_VALUE_ERROR_MSG "Error: Too Low Value"
#define TOO_LARGE_VALUE_ERROR_MSG "Error: Too Large Value"
#define TOO_LARGE_DATE_ERROR_MSG "Error: Too Large Date"
#define TOO_LOW_DATE_ERROR_MSG "Error: Too Low Date"

#define DATA_FILE "data/data.csv"
#define DB_KEY_VAL_SEPARATOR ','
#define BTC_MIN 0
#define BTC_MAX 1000

enum ErrorType {
  TOO_LOW_DATE = -1,
  TOO_LARGE_DATE = -2,
  NO_SEPARATOR = -3,
  INVALID_DATE = -4,
  INVALID_NUMBER = -5
};

namespace btcdata {
std::pair<std::time_t, double> parseAndValidateLine(std::string line,
                                                    char separator);
std::map<std::time_t, double> parseFileDb(const char *filename);

class parseException : public std::exception {
 public:
  parseException(std::string msg) : _msg("PARSING ERROR: " + msg){};
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

class btcException : public std::exception {
 public:
  btcException(std::string msg) : _msg("BTC ERROR: " + msg){};
  virtual ~btcException() throw() {}
  virtual const char *what() const throw() { return _msg.c_str(); }

 private:
  std::string _msg;
};
}  // namespace btc

#endif