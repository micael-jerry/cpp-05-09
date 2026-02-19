/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:17:37 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/18 22:35:57 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

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
  int min = std::numeric_limits<int>::max();

  for (unsigned int i = 0; i < this->_contents.size() - 1; i++) {
    for (unsigned int j = i + 1; j < this->_contents.size(); j++) {
      int newMin = std::abs(this->_contents[i] - this->_contents[j]);
      if (newMin < min) {
        min = newMin;
      }
    }
  }
  return min;
}

int Span::longestSpan() const {
  if (this->_contents.size() < 2) {
    throw Span::NotEnoughNumbersException();
  }
  int max = std::numeric_limits<int>::min();

  for (unsigned int i = 0; i < this->_contents.size() - 1; i++) {
    for (unsigned int j = i + 1; j < this->_contents.size(); j++) {
      int newMax = std::abs(this->_contents[i] - this->_contents[j]);
      if (newMax > max) {
        max = newMax;
      }
    }
  }
  return max;
}

unsigned int Span::getSize() const { return this->_size; }

std::vector<int> Span::getContents() const { return this->_contents; }
