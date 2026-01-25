/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:52:28 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/25 17:41:04 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#define PRESIDENTIAL_PARDON_FORM_SIGN_GRADE_REQUIRED 25
#define PRESIDENTIAL_PARDON_FORM_EXEC_GRADE_REQUIRED 5

#include "./AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string _target;
  PresidentialPardonForm();

 public:
  PresidentialPardonForm(std::string const &target);
  PresidentialPardonForm(PresidentialPardonForm const &src);

  ~PresidentialPardonForm();

  PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

  std::string const &getTarget() const;
  void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &form);

#endif
