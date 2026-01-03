/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 06:57:52 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/03 06:57:55 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default_bureaucrat") {}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade): _name(name), _grade(grade) {
  if (grade < BUREAUCRAT_MAX_GRADE) throw Bureaucrat::GradeTooHighException();
  if (grade > BUREAUCRAT_MIN_GRADE) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : _name(src.getName()), _grade(src.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
  if (this == &src) return (*this);
  this->_grade = src.getGrade();
  return (*this);
}

std::string const &Bureaucrat::getName(void) const { return (this->_name); }

int const &Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::incrementGrade(void) {
  if ((this->_grade - 1) < BUREAUCRAT_MAX_GRADE)
    throw Bureaucrat::GradeTooHighException();
  this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
  if ((this->_grade + 1) > BUREAUCRAT_MIN_GRADE)
    throw Bureaucrat::GradeTooLowException();
  this->_grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << "." << std::endl;
  return (os);
}
