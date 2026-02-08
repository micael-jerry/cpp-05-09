/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 07:11:05 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/08 08:24:47 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class NotFoundException : public std::exception {
 public:
  virtual const char* what() const throw() {
    return "Value not found in container";
  }
};

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"

#endif