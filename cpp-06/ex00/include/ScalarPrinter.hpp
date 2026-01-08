/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarPrinter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 04:35:30 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/08 19:47:16 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_PRINTER_HPP
#define SCALAR_PRINTER_HPP

#include <string>

namespace ScalarPrinter {
void printCharBase(char const &chr);
void printIntBase(int const &integer);
void printFloatBase(float const &flt);
void printDoubleBase(double const &dbl);
void printSpecialBase(std::string const &spl);
void printInvalidBase(void);
}  // namespace ScalarPrinter

#endif