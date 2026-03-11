/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:54:40 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/11 06:10:11 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

namespace btcdata {
std::map<std::string, double> parseFileContent(const char *filename, char dateAndValueSeparator);
}

namespace btcutils {
bool isValidDate(std::string date);
bool isValidValue(std::string value);
}  // namespace btcutils

#endif