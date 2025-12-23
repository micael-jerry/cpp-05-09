/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/23 05:12:20 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main()
{
    Intern someIntern;
    Bureaucrat boss("Boss", 1);

    AForm *form;

    std::cout << "\n=== Valid form ===" << std::endl;
    form = someIntern.makeForm("ShrubberyCreationForm", "Test");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n=== Invalid form ===" << std::endl;
    form = someIntern.makeForm("unknown form", "Nobody");
    if (form)
        delete form;

    return 0;
}