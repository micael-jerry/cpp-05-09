/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:50:35 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/29 05:10:57 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP

#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &scalarConvert);
  ScalarConverter &operator=(ScalarConverter const &scalarConvert);

 public:
  ~ScalarConverter();

  static void convert(std::string const &toConvert);

 private:
  static char convertToChar(std::string const &toConvert);
  static int convertToInt(std::string const &toConvert);
  static float convertToFloat(std::string const &toConvert);
  static double convertToDouble(std::string const &toConvert);
};

#endif