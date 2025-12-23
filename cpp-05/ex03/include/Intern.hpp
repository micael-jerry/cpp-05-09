/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:46:44 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/23 05:13:22 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

class Intern {
 private:
  static AForm *presidentialPardonFormBuilder(std::string const &target);
  static AForm *robotomyRequestFormBuilder(std::string const &target);
  static AForm *shrubberyCreationFormBuilder(std::string const &target);

 public:
  Intern();
  Intern(Intern const &src);

  ~Intern();

  Intern &operator=(Intern const &src);

  AForm *makeForm(std::string const &formName, std::string const &target);
};

typedef struct s_form_builder {
  std::string name;
  AForm *(*builder)(std::string const &target);
} t_form_builder;

#endif