/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:30:02 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/20 21:49:15 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "../include/Span.hpp"

int main() {
  std::cout << "--- Test 1: Subject Test ---" << std::endl;
  try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n--- Test 2: 20000 elements ---" << std::endl;
  try {
    Span bigSpan = Span(20000);
    std::vector<int> randomNumbers;

    std::srand(std::time(0));
    for (int i = 0; i < 20000; ++i) {
      randomNumbers.push_back(std::rand());
    }

    bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());

    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}