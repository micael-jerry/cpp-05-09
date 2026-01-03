/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:34:06 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/03 08:54:29 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
 private:
  std::string const _name;
  bool _isSigned;
  int const _gradeToSign;
  int const _gradeToExecute;

 public:
  AForm();
  AForm(std::string const &name, int const &gradeToSign,
        int const &gradeToExecute);
  AForm(AForm const &src);

  virtual ~AForm();

  AForm &operator=(AForm const &src);

  std::string const &getName(void) const;
  bool const &getIsSigned(void) const;
  int const &getGradeToSign(void) const;
  int const &getGradeToExecute(void) const;
  void beSigned(Bureaucrat const &bureaucrat);
  void checkGrade(int const &grade, int const &minGrade,
                  int const &maxGrade) const;
  virtual void execute(Bureaucrat const &executor) const = 0;

 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw() { return ("Grade too high"); }
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw() { return ("Grade too low"); }
  };

  class NotSignedFormException : public std::exception {
   public:
    virtual const char *what() const throw() { return ("Form not signed"); }
  };
};

std::ostream &operator<<(std::ostream &o, AForm const &form);

#endif