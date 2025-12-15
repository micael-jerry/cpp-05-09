/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:54:17 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/16 05:53:23 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm():
	_name("default_form"),
	_isSigned(false),
	_gradeToSign(BUREAUCRAT_MAX_GRADE),
	_gradeToExecute(BUREAUCRAT_MAX_GRADE) {}

AForm::AForm(std::string const &name, int const &gradeToSign, int const &gradeToExecute) {
	this->checkGrade(gradeToSign, BUREAUCRAT_MIN_GRADE, BUREAUCRAT_MAX_GRADE);
	this->checkGrade(gradeToExecute, BUREAUCRAT_MIN_GRADE, BUREAUCRAT_MAX_GRADE);
	this->_name = name;
	this->_isSigned = false;
	this->_gradeToSign = gradeToSign;
	this->_gradeToExecute = gradeToExecute;
}

AForm::AForm(AForm const &src):
	_name(src.getName()),
	_isSigned(src.getIsSigned()),
	_gradeToSign(src.getGradeToSign()),
	_gradeToExecute(src.getGradeToExecute()) {}

AForm::~AForm() {}

AForm &AForm::operator=(AForm const &src) {
	if (this == &src)
		return *this;
	this->_name = src.getName();
	this->_isSigned = src.getIsSigned();
	this->_gradeToSign = src.getGradeToSign();
	this->_gradeToExecute = src.getGradeToExecute();
	return *this;
}

void AForm::checkGrade(int const &grade, int const &minGrade, int const &maxGrade) const
{
	if (grade < maxGrade)
		throw AForm::GradeTooHighException();
	if (grade > minGrade)
		throw AForm::GradeTooHighException();
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign) {
		this->_isSigned = true;
		return ;
	}
	throw AForm::GradeTooLowException();
}

std::string const &AForm::getName(void) const
{
	return this->_name;
}

bool const &AForm::getIsSigned(void) const
{
	return this->_isSigned;
}

int const &AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int const &AForm::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

std::ostream &operator<<(std::ostream &o, AForm const &form)
{
	std::cout
		<< form.getName()
		<< ": Signed:" << form.getIsSigned()
		<< " | GradeToSign:" << form.getGradeToSign()
		<< " | GradeToExecute" << form.getGradeToExecute();
	return o;
}
