/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:21:06 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/08 18:48:04 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
	std::vector<int> v;

public : Span();
 Span(unsigned int n);
 Span(Span const &span);

 ~Span();

 Span &operator=(Span const &span);

 void addNumber(int const &number);
 int shortestSpan();
 int longestSpan();
};

#endif