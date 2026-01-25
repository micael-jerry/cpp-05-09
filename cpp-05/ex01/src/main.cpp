/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/25 19:54:59 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

void testFormCreation() {
  std::cout << "=== Form Creation ===" << std::endl;
  try {
    Form f("Valid Form", 50, 50);
    std::cout << f << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    std::cout << "Creating form with sign grade 0..." << std::endl;
    Form f("Too High", 0, 50);
  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  try {
    std::cout << "Creating form with exec grade 151..." << std::endl;
    Form f("Too Low", 50, 151);
  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
}

void testSigning() {
  std::cout << "\n=== Signing Forms ===" << std::endl;
  Bureaucrat boss("Boss", 1);
  Bureaucrat employee("Employee", 100);
  Form contract("Contract", 50, 50);

  std::cout << contract << std::endl;

  std::cout << "-- Employee tries to sign --" << std::endl;
  employee.signForm(contract);
  std::cout << contract << std::endl;

  std::cout << "-- Boss signs --" << std::endl;
  boss.signForm(contract);
  std::cout << contract << std::endl;

  std::cout << "-- Boss tries to sign again --" << std::endl;
  boss.signForm(contract);
}

void testBeSigned() {
  std::cout << "\n=== beSigned Method ===" << std::endl;
  Bureaucrat intern("Intern", 150);
  Form simple("Simple Form", 150, 150);
  Form hard("Hard Form", 1, 1);

  try {
    std::cout << "Intern signing simple form..." << std::endl;
    simple.beSigned(intern);
    std::cout << simple << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    std::cout << "Intern signing hard form..." << std::endl;
    hard.beSigned(intern);
  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
}

int main() {
  testFormCreation();
  testSigning();
  testBeSigned();

  return 0;
}
