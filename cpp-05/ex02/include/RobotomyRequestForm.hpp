/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:52:28 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/16 21:05:47 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#define ROBOTOMYREQUESTFORM_SIGN_GRADE_REQUIRED 72
#define ROBOTOMYREQUESTFORM_EXEC_GRADE_REQUIRED 45

#include <cstdlib>
#include "./AForm.hpp"

class RobotomyRequestForm: public AForm
{
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
