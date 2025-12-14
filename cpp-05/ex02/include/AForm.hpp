/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:34:06 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/14 15:26:05 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "../include/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string _name;
	bool _isSigned;
	int _gradeToSign;
	int _gradeToExecute;
	void checkGrade(int const &grade) const;

public:
	AForm();
	AForm(std::string const &name, int const &gradeToSign, int const &gradeToExecute);
	AForm(AForm const &src);

	~AForm();

	AForm &operator=(AForm const &src);

	std::string const &getName(void) const;
	bool const &getIsSigned(void) const;
	int const &getGradeToSign(void) const;
	int const &getGradeToExecute(void) const;
	virtual void beSigned(Bureaucrat const &bureaucrat) = 0;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too low");
		}
	};
};

std::ostream &operator<<(std::ostream &o, AForm const &form);

#endif