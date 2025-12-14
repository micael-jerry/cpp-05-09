/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:34:06 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/14 05:38:14 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Form
{
private:
	std::string _name;
	bool _isSigned;
	int _gradeToSign;
	int _gradeToExecute;

public:
	Form();
	Form(std::string const &name, int const &gradeToSign, int const &gradeToExecute);
	Form(Form const &src);

	~Form();

	Form &operator=(Form const &src);

	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
};
