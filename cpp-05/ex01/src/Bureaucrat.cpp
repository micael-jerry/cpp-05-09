#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default_bureaucrat") {
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) {
  if (grade < BUREAUCRAT_MAX_GRADE)
    throw Bureaucrat::GradeTooHighException();
  if (grade > BUREAUCRAT_MIN_GRADE)
    throw Bureaucrat::GradeTooLowException();
  this->_name = name;
  this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : _name(src.getName()), _grade(src.getGrade()) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
  if (this == &src)
    return (*this);
  this->_name = src.getName();
  this->_grade = src.getGrade();
  return (*this);
}

std::string Bureaucrat::getName(void) const {
  return (this->_name);
}

int Bureaucrat::getGrade(void) const {
  return (this->_grade);
}

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

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << this->_name << " signed " << form.getName() << std::endl;
  } catch (Form::GradeTooLowException &e) {
    std::cout << this->_name << " couldn’t sign " << form.getName()
              << " because " << e.what() << "." << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << "." << std::endl;
  return (os);
}
