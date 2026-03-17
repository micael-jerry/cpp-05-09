/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:30:02 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/17 22:04:15 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "../include/Span.hpp"

int main() {
  std::cout << "\n========== TEST 1: SUBJECT TEST ==========" << std::endl;
  try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << " (Expected: 14)" << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  std::cout << "\n========== TEST 2: EXCEPTIONS TEST ==========" << std::endl;
  try {
    std::cout << "[Testing Span(0)]" << std::endl;
    Span emptySpan(0);
    emptySpan.addNumber(1); // Should throw OutOfRangeException
  } catch (std::exception &e) {
    std::cout << "\033[31mCaught Exception:\033[0m " << e.what() << std::endl;
  }

  try {
    std::cout << "\n[Testing shortestSpan with only 1 element]" << std::endl;
    Span oneElementSpan(5);
    oneElementSpan.addNumber(42);
    oneElementSpan.shortestSpan(); // Should throw NotEnoughNumbersException
  } catch (std::exception &e) {
    std::cout << "\033[31mCaught Exception:\033[0m " << e.what() << std::endl;
  }

  try {
    std::cout << "\n[Testing spanning over capacity]" << std::endl;
    Span sp(2);
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3); // Should throw OutOfRangeException
  } catch (std::exception &e) {
    std::cout << "\033[31mCaught Exception:\033[0m " << e.what() << std::endl;
  }

  std::cout << "\n========== TEST 3: ITERATOR RANGE ADDITION ==========" << std::endl;
  try {
    Span rangeSpan(10);
    std::vector<int> vec;
    for (int i = 0; i < 5; i++) {
        vec.push_back(i * 10);
    }
    
    std::cout << "Adding 5 numbers from vector to span..." << std::endl;
    rangeSpan.addNumber(vec.begin(), vec.end());
    
    std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << rangeSpan.longestSpan() << std::endl;
    
    std::cout << "\nTrying to add 10 more numbers (should overflow)..." << std::endl;
    std::vector<int> tooMany;
    for (int i = 0; i < 10; i++) tooMany.push_back(i);
    rangeSpan.addNumber(tooMany.begin(), tooMany.end()); // should throw
    
  } catch (std::exception &e) {
    std::cout << "\033[31mCaught Exception:\033[0m " << e.what() << std::endl;
  }

  std::cout << "\n========== TEST 4: 20,000 ELEMENTS PERFORMANCE ==========" << std::endl;
  try {
    Span bigSpan = Span(20000);
    std::vector<int> randomNumbers;

    std::srand(std::time(0));
    for (int i = 0; i < 20000; ++i) {
      randomNumbers.push_back(std::rand());
    }

    std::cout << "Adding 20,000 random elements..." << std::endl;
    bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());

    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << bigSpan.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}