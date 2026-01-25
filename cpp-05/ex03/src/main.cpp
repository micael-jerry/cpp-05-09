/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/25 20:07:15 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"

void testInternCreation() {
  std::cout << "=== Intern Making Forms ===" << std::endl;
  Intern someIntern;
  Bureaucrat boss("Boss", 1);

  AForm *form;

  std::cout << "\n-- Asking for RobotomyRequestForm --" << std::endl;
  form = someIntern.makeForm("robotomy request", "Bender");
  if (form) {
    std::cout << *form << std::endl;
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;
  }

  std::cout << "\n-- Asking for PresidentialPardonForm --" << std::endl;
  form = someIntern.makeForm("presidential pardon", "Arthur Dent");
  if (form) {
    std::cout << *form << std::endl;
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;
  }

  std::cout << "\n-- Asking for ShrubberyCreationForm --" << std::endl;
  form = someIntern.makeForm("shrubbery creation", "Home");
  if (form) {
    std::cout << *form << std::endl;
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;
  }
}

void testInvalidForm() {
  std::cout << "\n=== Intern failing to make form ===" << std::endl;
  Intern intern;
  AForm *form;

  form = intern.makeForm("not a form", "Nobody");
  if (form) {
    delete form;
  } else {
    std::cout << "Form was not created." << std::endl;
  }
}

int main(void) {
  std::srand(std::time(NULL));

  testInternCreation();
  testInvalidForm();

  return 0;
}