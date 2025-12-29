/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarPrinter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 04:38:50 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/29 05:19:40 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarPrinter.hpp"

#include <iostream>

void ScalarPrinter::printCharBase(char const &chr) {
  std::cout << "char: " << chr << std::endl
            << "int: " << chr << std::endl
            << "float: " << chr << ".0f" << std::endl
            << "double: " << chr << ".0" << std::endl;
}

void ScalarPrinter::printInvalidBase() {
  std::cout << "char: " << "impossible" << std::endl
            << "int: " << "impossible" << std::endl
            << "float: " << "impossible" << std::endl
            << "double: " << "impossible" << std::endl;
}
