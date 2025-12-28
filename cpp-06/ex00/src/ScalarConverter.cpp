/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:13 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/29 04:32:34 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/ScalarTypeUtil.hpp"

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string const &toConvert) {
  ScalarTypeUtil::printScalarValues(toConvert);
}