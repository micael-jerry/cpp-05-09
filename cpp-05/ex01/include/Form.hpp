/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:34:06 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/03 08:13:28 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
 private:
  std::string const _name;
  int const _gradeToSign;
  int const _gradeToExecute;
  bool _isSigned;

  void checkGrade(int const &grade) const;

 public:
  Form();
  Form(std::string const &name, int const &gradeToSign,
       int const &gradeToExecute);
  Form(Form const &src);

  ~Form();

  Form &operator=(Form const &src);

  std::string const &getName(void) const;
  bool const &getIsSigned(void) const;
  int const &getGradeToSign(void) const;
  int const &getGradeToExecute(void) const;

  void beSigned(Bureaucrat const &bureaucrat);

 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw() { return ("Grade too high"); }
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw() { return ("Grade too low"); }
  };
};

std::ostream &operator<<(std::ostream &o, Form const &form);

#endif