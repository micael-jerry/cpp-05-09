/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 06:25:28 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/22 19:19:38 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/Array.hpp"

template <typename T>
void printArray(const Array<T>& arr, const std::string& name) {
  std::cout << "----- " << name << " -----" << std::endl;
  std::cout << "Size: " << arr.size() << std::endl;
  for (unsigned int i = 0; i < arr.size(); i++)
    std::cout << name << "[" << i << "] = " << arr[i] << std::endl;
  std::cout << std::endl;
}

int main() {
  {
    std::cout << "========== TEST 1: Default constructor =========="
              << std::endl;
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;

    try {
      empty[0];
    } catch (std::exception& e) {
      std::cout << "Exception caught (empty access): " << e.what() << std::endl;
    }
  }

  std::cout << "\n========== TEST 2: Constructor with size =========="
            << std::endl;
  Array<int> numbers(5);

  for (unsigned int i = 0; i < numbers.size(); i++) {
    numbers[i] = i * 10;
  }

  printArray(numbers, "numbers");

  std::cout << "Testing out of bounds..." << std::endl;
  try {
    numbers[100];
  } catch (std::exception& e) {
    std::cout << "Exception caught (out of bounds): " << e.what() << std::endl;
  }

  std::cout << "\n========== TEST 3: Copy constructor ==========" << std::endl;
  Array<int> copy(numbers);

  printArray(copy, "copy");

  std::cout << "Modifying original numbers[0] = 999" << std::endl;
  numbers[0] = 999;

  printArray(numbers, "numbers");
  printArray(copy, "copy (must NOT change)");

  std::cout << "\n========== TEST 4: Assignment operator =========="
            << std::endl;
  Array<int> assigned;
  assigned = numbers;

  printArray(assigned, "assigned");

  std::cout << "Modifying assigned[1] = 555" << std::endl;
  assigned[1] = 555;

  printArray(numbers, "numbers (must NOT change)");
  printArray(assigned, "assigned");

  std::cout << "\n========== TEST 7: Different type (std::string) =========="
            << std::endl;
  Array<std::string> words(3);
  words[0] = "Hello";
  words[1] = "42";
  words[2] = "Templates";

  printArray(words, "words");

  std::cout << "\n========== ALL TESTS FINISHED ==========" << std::endl;

  return 0;
}