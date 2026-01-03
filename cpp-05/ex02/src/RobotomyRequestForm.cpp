/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 04:57:51 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/03 08:51:08 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

#include <cstdlib>

#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("robotomy_request_form", ROBOTOMY_REQUEST_FORM_SIGN_GRADE_REQUIRED,
            ROBOTOMY_REQUEST_FORM_EXEC_GRADE_REQUIRED),
      _target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("robotomy_request_form", ROBOTOMY_REQUEST_FORM_SIGN_GRADE_REQUIRED,
            ROBOTOMY_REQUEST_FORM_EXEC_GRADE_REQUIRED),
      _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
    : AForm(src) {
  this->_target = src.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    RobotomyRequestForm const &src) {
  if (this == &src) return (*this);
  AForm::operator=(src);
  this->_target = src.getTarget();
  return (*this);
}

std::string const &RobotomyRequestForm::getTarget() const {
  return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned()) {
    throw AForm::NotSignedFormException();
  }
  this->checkGrade(executor.getGrade(), this->getGradeToSign(),
                   BUREAUCRAT_MAX_GRADE);
  this->checkGrade(executor.getGrade(), this->getGradeToExecute(),
                   BUREAUCRAT_MAX_GRADE);
  if (this->isRobotomizationSuccess()) {
    std::cout << "BRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl
              << this->_target << " has been robotomized successfully"
              << std::endl;
  } else {
    std::cout << "Robotomy failed" << std::endl;
  }
}

bool RobotomyRequestForm::isRobotomizationSuccess() const {
  return (std::rand() % 2);
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &form) {
  std::cout << form.getName() << ": Signed:" << form.getIsSigned()
            << " | GradeToSign:" << form.getGradeToSign()
            << " | GradeToExecute:" << form.getGradeToExecute()
            << " | Target:" << form.getTarget();
  return o;
}