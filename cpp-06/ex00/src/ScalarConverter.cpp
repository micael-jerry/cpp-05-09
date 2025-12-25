/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:13 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/25 19:21:54 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/ScalarConverter.hpp"
#include "../include/ScalarUtils.hpp"

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string const &toConvert) {
  std::cout << ScalarUtils::detectScalarType(toConvert) << std::endl;
}