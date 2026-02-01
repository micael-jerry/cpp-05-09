/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 05:16:41 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/01 13:51:00 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _contents(new T[0]) {}

template <typename T>
Array<T>::Array(unsigned int n) : _contents(new T[n]) {}

template <typename T>
Array<T>::Array(Array<T> const &arr) {
  const unsigned int arrSize = arr.size();
  this->_contents = new T[arrSize];

  for (unsigned int i = 0; i < arrSize; i++) {
    this->_contents[i] = arr[i];
  }
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &arr) {
  if (this == &arr) {
    return *this;
  }

  const unsigned int arrSize = arr.size();
  delete[] this->_contents;
  this->_contents = new T[arrSize];

  for (unsigned int i = 0; i < arrSize; i++) {
    this->_contents[i] = arr[i];
  }

  return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) const {
  // TODO: ajouter une autre attribut pour stocker le size ou trouver un moyen pour faire en sorte que size retourne toute la zone memoire occuper au lieu de verifier jute ce qui on des element
  const unsigned int size = this->size();

  if (index >= size) {
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
  unsigned int size = 0;

  while (this->_contents[size]) {
    size++;
  }

  return size;
}
