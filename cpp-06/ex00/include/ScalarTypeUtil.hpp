/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypeUtil.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 05:34:00 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/08 19:43:31 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_TYPE_UTIL_HPP
#define SCALAR_TYPE_UTIL_HPP

#include <string>

namespace ScalarTypeUtil {
enum ScalarType {
  SCALAR_CHAR = 86,
  SCALAR_INT = 87,
  SCALAR_FLOAT = 88,
  SCALAR_DOUBLE = 89,
  SCALAR_SPECIAL = 90,
  SCALAR_INVALID = 91
};

ScalarType detectScalarType(std::string const &str);
}  // namespace ScalarTypeUtil

#endif