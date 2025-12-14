/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:34:06 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/14 10:49:07 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../include/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string _name;
	bool _isSigned;
	int _gradeToSign;
	int _gradeToExecute;
	void checkGrade(int const &grade) const;

public:
	Form();
	Form(std::string const &name, int const &gradeToSign, int const &gradeToExecute);
	Form(Form const &src);

	~Form();

	Form &operator=(Form const &src);

	std::string const &getName(void) const;
	bool const &getIsSigned(void) const;
	int const &getGradeToSign(void) const;
	int const &getGradeToExecute(void) const;
	void beSigned(Bureaucrat const &bureaucrat);

public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() throw()
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() throw()
		{
			return ("Grade too low");
		}
	};
};

std::ostream &operator<<(std::ostream &o, Form const &form);
