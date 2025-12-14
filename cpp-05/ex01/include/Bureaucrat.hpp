/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:06:39 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/14 10:51:49 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define BUREAUCRAT_MAX_GRADE 1
#define BUREAUCRAT_MIN_GRADE 150

#include <string>
#include <iostream>
#include "../include/Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int const &grade);
	Bureaucrat(Bureaucrat const &src);

	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &src);

	std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(Form const &form) const;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too high");
		};
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too low");
		};
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const &obj);

#endif
