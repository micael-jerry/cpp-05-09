/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 04:57:51 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/03 08:31:38 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

#include <fstream>

#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("shrubbery_creation_form",
            SHRUBBERY_CREATION_FORM_SIGN_GRADE_REQUIRED,
            SHRUBBERY_CREATION_FORM_EXEC_GRADE_REQUIRED),
      _target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("shrubbery_creation_form",
            SHRUBBERY_CREATION_FORM_SIGN_GRADE_REQUIRED,
            SHRUBBERY_CREATION_FORM_EXEC_GRADE_REQUIRED),
      _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
    : AForm(src) {
  this->_target = src.getTarget();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &src) {
  if (this == &src) return (*this);
  AForm::operator=(src);
  this->_target = src.getTarget();
  return (*this);
}

std::string const &ShrubberyCreationForm::getTarget() const {
  return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned()) {
    throw AForm::NotSignedFormException();
  }
  this->checkGrade(executor.getGrade(), this->getGradeToSign(),
                   BUREAUCRAT_MAX_GRADE);
  this->checkGrade(executor.getGrade(), this->getGradeToExecute(),
                   BUREAUCRAT_MAX_GRADE);
  this->writeTreeInFile(this->_target);
}

int ShrubberyCreationForm::writeTreeInFile(std::string const &filename) const {
  std::string finalFileName = filename + "_shrubbery";
  std::ofstream file(finalFileName.c_str());

  if (!file.is_open()) {
    return 1;
  }

  file << "            *\n"
          "           /***\\\n"
          "          /*****\\\n"
          "         /*******\\\n"
          "        /***  *  ***\\\n"
          "       /***************\\\n"
          "      /*****  ***  *****\\\n"
          "     /*******************\\\n"
          "    /***  ***   ***  ***  ***\\\n"
          "   /***************************\\\n"
          "              |||\n"
          "              |||\n"
          "              |||\n";

  file.close();
  return 0;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &form) {
  std::cout << form.getName() << ": Signed:" << form.getIsSigned()
            << " | GradeToSign:" << form.getGradeToSign()
            << " | GradeToExecute:" << form.getGradeToExecute()
            << " | Target:" << form.getTarget();
  return o;
}