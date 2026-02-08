/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 04:52:34 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/08 05:59:49 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
 private:
  unsigned int _size;
  T *_contents;

 public:
  Array();
  Array(unsigned int n);
  Array(Array<T> const &arr);

  Array<T> &operator=(Array<T> const &arr);
  T &operator[](unsigned int index) const;

  ~Array();

  unsigned int size() const;

  class OutOfBoundsException : public std::exception {
   public:
    const char *what() const throw() { return "Out of bounds"; }
  };
};

#include "Array.tpp"

#endif