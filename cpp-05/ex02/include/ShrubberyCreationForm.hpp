/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:52:28 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/03 08:30:32 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#define SHRUBBERY_CREATION_FORM_SIGN_GRADE_REQUIRED 145
#define SHRUBBERY_CREATION_FORM_EXEC_GRADE_REQUIRED 137

#include "./AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;
  ShrubberyCreationForm();
  int writeTreeInFile(std::string const &filename) const;

 public:
  ShrubberyCreationForm(std::string const &target);
  ShrubberyCreationForm(ShrubberyCreationForm const &src);

  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

  std::string const &getTarget() const;
  void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &form);

#endif
