#include "../include/Bureaucrat.hpp"

#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat()
    : _name("default_bureaucrat"), _grade(BUREAUCRAT_MIN_GRADE) {}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade)
    : _name(name), _grade(grade) {
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

void Bureaucrat::signForm(AForm &form) const throw() {
  try {
    form.beSigned(*this);
    std::cout << this->_name << " signed " << form.getName() << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << this->_name << " couldn't sign " << form.getName()
              << " because " << e.what() << "." << std::endl;
  }
}

void Bureaucrat::executeForm(AForm &form) const {
  try {
    form.execute(*this);
    std::cout << this->_name << " executed " << form.getName() << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << this->_name << " couldn't execute " << form.getName()
              << " because " << e.what() << "." << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << "." << std::endl;
  return (os);
}
