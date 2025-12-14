/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:54:17 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/14 05:58:51 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form():
	_name("default_form"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150) {}

Form::Form(std::string const &name, int const &gradeToSign, int const &gradeToExecute):
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {}

Form::Form(Form const &src):
	_name(src.getName()),
	_isSigned(src.getIsSigned()),
	_gradeToSign(src.getGradeToSign()),
	_gradeToExecute(src.getGradeToExecute()) {}
