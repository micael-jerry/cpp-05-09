/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/25 20:06:29 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

void testShrubbery() {
  std::cout << "\n=== ShrubberyCreationForm ===" << std::endl;
  try {
    Bureaucrat bob("Bob", 137);
    ShrubberyCreationForm tree("home");

    std::cout << tree << std::endl;
    bob.signForm(tree);
    bob.executeForm(tree);
    std::cout << "Check home_shrubbery file." << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
}

void testRobotomy() {
  std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
  try {
    Bureaucrat marvin("Marvin", 45);
    RobotomyRequestForm robot("Bender");

    std::cout << robot << std::endl;
    marvin.signForm(robot);

    std::cout << "--- Executing multiple times to check 50% chance ---"
              << std::endl;
    for (int i = 0; i < 4; ++i) {
      std::cout << "Attempt " << i + 1 << ": ";
      marvin.executeForm(robot);
    }
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
}

void testPresidential() {
  std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
  try {
    Bureaucrat zaphod("Zaphod", 5);
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << pardon << std::endl;
    zaphod.signForm(pardon);
    zaphod.executeForm(pardon);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
}

void testFailures() {
  std::cout << "\n=== Failures ===" << std::endl;
  Bureaucrat intern("Intern", 150);
  Bureaucrat manager("Manager", 100);
  ShrubberyCreationForm form("failure_test");

  std::cout << "-- Execute unsigned form --" << std::endl;
  try {
    manager.executeForm(form);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << "-- Sign but exec grade too low --" << std::endl;
  manager.signForm(form);
  intern.executeForm(form);
}

int main() {
  std::srand(std::time(NULL));

  testShrubbery();
  testRobotomy();
  testPresidential();
  testFailures();

  return 0;
}