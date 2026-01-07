/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/04 17:39:43 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"

int main() {
  try {
    Intern someIntern;
    Bureaucrat boss("Boss", 1);

    AForm* form;

    std::cout << "\n=== Valid form ===" << std::endl;
    form = someIntern.makeForm("ShrubberyCreationForm", "Test");
    if (form) {
      boss.signForm(*form);
      boss.executeForm(*form);
      delete form;
    }

    std::cout << "\n=== Invalid form ===" << std::endl;
    form = someIntern.makeForm("unknown form", "Nobody");
    if (form) delete form;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}