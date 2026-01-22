/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/20 06:07:49 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main() {
  std::srand(std::time(NULL));

  try {
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 140);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "\n=== Signing forms ===" << std::endl;
    boss.signForm(shrub);
    boss.signForm(robot);
    boss.signForm(pardon);

    std::cout << "\n=== Executing forms ===" << std::endl;
    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pardon);

    std::cout << "\n=== Execution failure (grade too low) ===" << std::endl;
    worker.executeForm(shrub);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}