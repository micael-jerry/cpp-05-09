/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:17:37 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/22 22:28:55 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <limits>
#include <vector>

Span::Span() : _size(0) {}

Span::Span(unsigned int size) : _size(size) {}

Span::Span(Span const &span) {
  this->_size = span.getSize();
  this->_contents = span.getContents();
}

Span::~Span() {}

Span &Span::operator=(Span const &span) {
  if (this != &span) {
    this->_size = span.getSize();
    this->_contents = span.getContents();
  }
  return *this;
}

void Span::addNumber(int const &number) {
  if (this->_size == this->_contents.size()) {
    throw Span::OutOfRangeException();
  }
  this->_contents.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator start,
                     std::vector<int>::iterator end) {
  if (this->_contents.size() + std::distance(start, end) > this->_size) {
    throw Span::OutOfRangeException();
  }
  this->_contents.insert(this->_contents.end(), start, end);
}

int Span::shortestSpan() const {
  if (this->_contents.size() < 2) {
    throw Span::NotEnoughNumbersException();
  }
  std::vector<int> contentTmp = this->_contents;
  std::sort(contentTmp.begin(), contentTmp.end());

  int min = contentTmp[1] - contentTmp[0];

  for (size_t i = 1; i < contentTmp.size() - 1; i++) {
    int newMin = contentTmp[i + 1] - contentTmp[i];
    if (newMin < min) {
      min = newMin;
    }
  }

  return min;
}

int Span::longestSpan() const {
  if (this->_contents.size() < 2) {
    throw Span::NotEnoughNumbersException();
  }
  std::vector<int>::const_iterator itMin = std::min_element(this->_contents.begin(), this->_contents.end());
  std::vector<int>::const_iterator itMax = std::max_element(this->_contents.begin(), this->_contents.end());

  return (*itMax - *itMin);
}

unsigned int Span::getSize() const { return this->_size; }

std::vector<int> Span::getContents() const { return this->_contents; }
