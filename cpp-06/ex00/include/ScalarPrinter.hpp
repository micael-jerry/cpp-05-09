/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarPrinter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 04:35:30 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/04 06:11:06 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_PRINTER_HPP
#define SCALAR_PRINTER_HPP

namespace ScalarPrinter {
void printCharBase(char const &chr);
void printIntBase(int const &integer);
void printFloatBase(float const &flt);
void printDoubleBase(double const &dbl);
void printInvalidBase(void);
}  // namespace ScalarPrinter

#endif