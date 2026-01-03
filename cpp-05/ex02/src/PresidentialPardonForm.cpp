/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 04:57:51 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/03 08:51:10 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

#include "../include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("presidential_pardon_form",
            PRESIDENTIAL_PARDON_FORM_SIGN_GRADE_REQUIRED,
            PRESIDENTIAL_PARDON_FORM_EXEC_GRADE_REQUIRED),
      _target("default_target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("presidential_pardon_form",
            PRESIDENTIAL_PARDON_FORM_SIGN_GRADE_REQUIRED,
            PRESIDENTIAL_PARDON_FORM_EXEC_GRADE_REQUIRED),
      _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &src)
    : AForm(src) {
  this->_target = src.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    PresidentialPardonForm const &src) {
  if (this == &src) return (*this);
  AForm::operator=(src);
  this->_target = src.getTarget();
  return (*this);
}

std::string const &PresidentialPardonForm::getTarget() const {
  return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned()) {
    throw AForm::NotSignedFormException();
  }
  this->checkGrade(executor.getGrade(), this->getGradeToSign(),
                   BUREAUCRAT_MAX_GRADE);
  this->checkGrade(executor.getGrade(), this->getGradeToExecute(),
                   BUREAUCRAT_MAX_GRADE);
  std::cout << this->_target << " has been pardoned by Zafod Beeblebrox"
            << std::endl;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &form) {
  std::cout << form.getName() << ": Signed:" << form.getIsSigned()
            << " | GradeToSign:" << form.getGradeToSign()
            << " | GradeToExecute:" << form.getGradeToExecute()
            << " | Target:" << form.getTarget();
  return o;
}