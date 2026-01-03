/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:52:28 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/03 08:24:31 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#define ROBOTOMY_REQUEST_FORM_SIGN_GRADE_REQUIRED 72
#define ROBOTOMY_REQUEST_FORM_EXEC_GRADE_REQUIRED 45

#include "./AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string _target;
  RobotomyRequestForm();
  bool isRobotomizationSuccess() const;

 public:
  RobotomyRequestForm(std::string const &target);
  RobotomyRequestForm(RobotomyRequestForm const &src);

  ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

  std::string const &getTarget() const;
  void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &form);

#endif
