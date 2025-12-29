/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarPrinter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 04:38:50 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/29 05:39:53 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarPrinter.hpp"

#include <iostream>

void ScalarPrinter::printCharBase(char const &chr) {
  std::cout << "char: " << chr << std::endl
            << "int: " << static_cast<int>(chr) << std::endl
            << "float: " << static_cast<float>(chr) << ".0f" << std::endl
            << "double: " << static_cast<double>(chr) << ".0" << std::endl;
}

void ScalarPrinter::printInvalidBase() {
  std::cout << "char: " << "impossible" << std::endl
            << "int: " << "impossible" << std::endl
            << "float: " << "impossible" << std::endl
            << "double: " << "impossible" << std::endl;
}
