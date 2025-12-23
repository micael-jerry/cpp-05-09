/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:58:15 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/23 05:07:33 by mfidimal         ###   ########.fr       */
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

Intern::Intern() {
}

Intern::Intern(Intern const &src) {
  (void)src;
}

Intern::~Intern() {
}

Intern &Intern::operator=(Intern const &src) {
  (void)src;
  return *this;
}

AForm *Intern::makeForm(std::string const &formName,
                        std::string const &target) {
  static t_form_builder formBuilderContainer[] = {
      {"PresidentialPardonForm", &Intern::presidentialPardonFormBuilder},
      {"RobotomyRequestForm", &Intern::robotomyRequestFormBuilder},
      {"ShrubberyCreationForm", &Intern::shrubberyCreationFormBuilder}};

  for (int i; i < 3; i++) {
    if (formName == formBuilderContainer[i].name) {
      std::cout << "Intern create " << formName << std::endl;
      return formBuilderContainer[i].builder(target);
    }
  }
  std::cout << "Intern cannot create form: " << formName << std::endl;
  return NULL;
}