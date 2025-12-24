/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:50:35 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/24 05:43:18 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP

#include <string>
#include <iostream>
#include "./ScalarUtils.hpp"

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &scalarConvert);
  ScalarConverter &operator=(ScalarConverter const &scalarConvert);

 public:
  ~ScalarConverter();

  static void convert(std::string const &toConvert);
};

#endif