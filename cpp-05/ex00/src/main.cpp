/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/25 19:53:57 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Bureaucrat.hpp"

void testValidCcreation() {
  std::cout << "=== Valid creation ===" << std::endl;
  try {
    Bureaucrat bob("Bob", 42);
    std::cout << bob << std::endl;

    bob.incrementGrade();
    std::cout << "After increment: " << bob << std::endl;

    bob.decrementGrade();
    std::cout << "After decrement: " << bob << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

void testInvalidCreation() {
  std::cout << "\n=== Invalid creation ===" << std::endl;
  try {
    std::cout << "Attempting to create Jim with grade 151..." << std::endl;
    Bureaucrat jim("Jim", 151);
    std::cout << jim << std::endl;  // Should not be reached
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    std::cout << "Attempting to create Joe with grade 0..." << std::endl;
    Bureaucrat joe("Joe", 0);
    std::cout << joe << std::endl;  // Should not be reached
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
}

void testGradeBoundaries() {
  std::cout << "\n=== Grade boundaries ===" << std::endl;
  try {
    Bureaucrat king("King", 1);
    std::cout << king << std::endl;
    std::cout << "Attempting to increment grade 1..." << std::endl;
    king.incrementGrade();
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    Bureaucrat peasant("Peasant", 150);
    std::cout << peasant << std::endl;
    std::cout << "Attempting to decrement grade 150..." << std::endl;
    peasant.decrementGrade();
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
}

int main(void) {
  testValidCcreation();
  testInvalidCreation();
  testGradeBoundaries();

  return 0;
}