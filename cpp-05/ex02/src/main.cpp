/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/17 05:24:36 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
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

    return 0;
}