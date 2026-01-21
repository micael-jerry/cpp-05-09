/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 05:08:02 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/21 05:18:03 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
  T tmp = a;

  a = b;
  b = tmp;
}

template <typename T>
T max(T const &a, T const &b) {
  return (a > b ? a : b);
}

template <typename T>
T min(T const &a, T const &b) {
  return (a < b ? a : b);
}

#endif