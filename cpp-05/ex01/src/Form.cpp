/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:54:17 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/03 08:14:03 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

#include "../include/Bureaucrat.hpp"

Form::Form()
    : _name("default_form"),
      _gradeToSign(BUREAUCRAT_MAX_GRADE),
      _gradeToExecute(BUREAUCRAT_MAX_GRADE),
      _isSigned(false) {}

Form::Form(std::string const &name, int const &gradeToSign,
           int const &gradeToExecute)
    : _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _isSigned(false) {
  this->checkGrade(gradeToSign);
  this->checkGrade(gradeToExecute);
}

Form::Form(Form const &src)
    : _name(src.getName()),
      _gradeToSign(src.getGradeToSign()),
      _gradeToExecute(src.getGradeToExecute()),
      _isSigned(src.getIsSigned()) {}

Form::~Form() {}

Form &Form::operator=(Form const &src) {
  if (this == &src) {
    return *this;
  }
  this->_isSigned = src.getIsSigned();
  return *this;
}

void Form::checkGrade(int const &grade) const {
  if (grade < BUREAUCRAT_MAX_GRADE) throw Form::GradeTooHighException();
  if (grade > BUREAUCRAT_MIN_GRADE) throw Form::GradeTooLowException();
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() <= this->_gradeToSign) {
    this->_isSigned = true;
    return;
  }
  throw Form::GradeTooLowException();
}

std::string const &Form::getName(void) const { return this->_name; }

bool const &Form::getIsSigned(void) const { return this->_isSigned; }

int const &Form::getGradeToSign(void) const { return this->_gradeToSign; }

int const &Form::getGradeToExecute(void) const { return this->_gradeToExecute; }

std::ostream &operator<<(std::ostream &o, Form const &form) {
  std::cout << form.getName() << ": Signed:" << form.getIsSigned()
            << " | GradeToSign:" << form.getGradeToSign()
            << " | GradeToExecute:" << form.getGradeToExecute();
  return o;
}
