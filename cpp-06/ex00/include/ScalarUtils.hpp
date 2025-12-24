/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarUtils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 05:34:00 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/24 05:47:53 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_UTILS_HPP
#define SCALAR_UTILS_HPP

#include <string>

namespace ScalarUtils {
enum ScalarType {
  SCALAR_CHAR = 86,
  SCALAR_INT = 87,
  SCALAR_FLOAT = 88,
  SCALAR_DOUBLE = 89,
  SCALAR_INVALID = 90
};

ScalarType detectScalarType(std::string const &str);
}

#endif