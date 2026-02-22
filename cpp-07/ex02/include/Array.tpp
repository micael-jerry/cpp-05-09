/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 05:16:41 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/22 19:29:06 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _contents(new T[0]) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _contents(new T[n]) {}

template <typename T>
Array<T>::Array(Array<T> const &arr) {
  const unsigned int arrSize = arr.size();

  this->_size = arrSize;
  this->_contents = new T[arrSize];

  for (unsigned int i = 0; i < arrSize; i++) {
    this->_contents[i] = arr._contents[i];
  }
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &arr) {
  if (this == &arr) {
    return *this;
  }

  const unsigned int arrSize = arr.size();

  delete[] this->_contents;
  this->_size = arrSize;
  this->_contents = new T[arrSize];

  for (unsigned int i = 0; i < arrSize; i++) {
    this->_contents[i] = arr._contents[i];
  }

  return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) const {
  if (index >= this->_size) {
    throw Array<T>::OutOfBoundsException();
  }

  return this->_contents[index];
}

template <typename T>
Array<T>::~Array() {
  delete[] this->_contents;
}

template <typename T>
unsigned int Array<T>::size() const {
  return this->_size;
}
