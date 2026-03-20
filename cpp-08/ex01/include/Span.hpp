/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:21:06 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/20 06:42:53 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span {
 private:
  unsigned int _size;
  std::vector<int> _contents;

 public:
  Span();
  Span(unsigned int n);
  Span(Span const &span);

  ~Span();

  Span &operator=(Span const &span);

  void addNumber(int const &number);
  template<typename Tit>
  void addNumber(Tit start, Tit end) {
  if (this->_contents.size() + std::distance(start, end) > this->_size) {
    throw Span::OutOfRangeException();
  }
  this->_contents.insert(this->_contents.end(), start, end);
  }

  int shortestSpan() const;
  int longestSpan() const;

  unsigned int getSize() const;
  std::vector<int> getContents() const;

  class OutOfRangeException : public std::exception {
    virtual const char *what() const throw() { return "Span is full"; }
  };

  class NotEnoughNumbersException : public std::exception {
    virtual const char *what() const throw() {
      return "Not enough numbers to compute a span";
    }
  };
};

#endif