/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:54:17 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/17 05:36:57 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form()
    : _name("default_form"),
      _isSigned(false),
      _gradeToSign(BUREAUCRAT_MAX_GRADE),
      _gradeToExecute(BUREAUCRAT_MAX_GRADE) {
}

Form::Form(std::string const &name, int const &gradeToSign,
           int const &gradeToExecute) {
  this->checkGrade(gradeToSign);
  this->checkGrade(gradeToExecute);
  this->_name = name;
  this->_isSigned = false;
  this->_gradeToSign = gradeToSign;
  this->_gradeToExecute = gradeToExecute;
}

Form::Form(Form const &src)
    : _name(src.getName()),
      _isSigned(src.getIsSigned()),
      _gradeToSign(src.getGradeToSign()),
      _gradeToExecute(src.getGradeToExecute()) {
}

Form::~Form() {
}

Form &Form::operator=(Form const &src) {
  if (this == &src)
    return *this;
  this->_name = src.getName();
  this->_isSigned = src.getIsSigned();
  this->_gradeToSign = src.getGradeToSign();
  this->_gradeToExecute = src.getGradeToExecute();
  return *this;
}

void Form::checkGrade(int const &grade) const {
  if (grade < BUREAUCRAT_MAX_GRADE)
    throw Form::GradeTooHighException();
  if (grade > BUREAUCRAT_MIN_GRADE)
    throw Form::GradeTooLowException();
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() <= this->_gradeToSign) {
    this->_isSigned = true;
    return;
  }
  throw Form::GradeTooLowException();
}

std::string const &Form::getName(void) const {
  return this->_name;
}

bool const &Form::getIsSigned(void) const {
  return this->_isSigned;
}

int const &Form::getGradeToSign(void) const {
  return this->_gradeToSign;
}

int const &Form::getGradeToExecute(void) const {
  return this->_gradeToExecute;
}

std::ostream &operator<<(std::ostream &o, Form const &form) {
  std::cout << form.getName() << ": Signed:" << form.getIsSigned()
            << " | GradeToSign:" << form.getGradeToSign()
            << " | GradeToExecute:" << form.getGradeToExecute();
  return o;
}
