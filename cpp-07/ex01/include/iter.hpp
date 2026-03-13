/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 05:25:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/13 05:28:27 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename Fn>
void iter(T *array, std::size_t const length, Fn f) {
  for (std::size_t i = 0; i < length; i++) {
    f(array[i]);
  }
}

#endif