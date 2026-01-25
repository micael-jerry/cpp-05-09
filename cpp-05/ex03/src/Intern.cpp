/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:58:15 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/25 19:40:17 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

AForm *Intern::presidentialPardonFormBuilder(std::string const &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::robotomyRequestFormBuilder(std::string const &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::shrubberyCreationFormBuilder(std::string const &target) {
  return new ShrubberyCreationForm(target);
}

Intern::Intern() {}

Intern::Intern(Intern const &src) { (void)src; }

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &src) {
  (void)src;
  return *this;
}

AForm *Intern::makeForm(std::string const &formName,
                        std::string const &target) {
  static t_form_builder formBuilderContainer[] = {
      {"presidential pardon", &Intern::presidentialPardonFormBuilder},
      {"robotomy request", &Intern::robotomyRequestFormBuilder},
      {"shrubbery creation", &Intern::shrubberyCreationFormBuilder}};

  for (int i = 0; i < 3; i++) {
    if (formName == formBuilderContainer[i].name) {
      std::cout << "Intern create " << formName << std::endl;
      return formBuilderContainer[i].builder(target);
    }
  }
  std::cout << "Intern cannot create form: " << formName << std::endl;
  return NULL;
}