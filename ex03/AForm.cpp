/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:41:27 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/26 18:44:47 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("DefaultForm"), _signed(false), _signGrade(1), _execGrade(1)
{
	std::cout << _name << " has been created." << std::endl;

	return;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	// std::cout << _name << " has been created." << std::endl;

	return;
}

AForm::AForm(const AForm& src) : _name(src.getName()), _signed(src.getSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	return;
}

AForm::~AForm()
{
	return;
}

AForm&				AForm::operator=(const AForm& rhs)
{
	_signed = rhs.getSigned();													// No other non-const attributes in the class

	return (*this);
}

const std::string	AForm::getName() const		{return (_name);}
bool				AForm::getSigned() const		{return (_signed);}
int					AForm::getSignGrade() const	{return (_signGrade);}
int					AForm::getExecGrade() const	{return (_execGrade);}

bool				AForm::beSigned(const Bureaucrat& bur)
{
	try
	{
		if (bur.getGrade() > _signGrade)
			throw (Bureaucrat::GradeTooLowException());
		else
		{
			_signed = true;
			// std::cout << _name << " has been signed by " << bur.getName() << std::endl;
			return (true);
		}
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		return (false);
	}

	return (false);
}

std::ostream&		operator<<(std::ostream& o, const AForm& i)
{
	o << "Form:    " << i.getName() << std::endl;
	o << "Status:  ";
	
	if (i.getSigned() == true)
		o << "signed" << std::endl;
	else
		o << "not signed" << std::endl;

	o << "Required grade to sign:    " << i.getSignGrade() << std::endl;
	o << "Required grade to execute: " << i.getExecGrade() << std::endl;

	return (o);
}

const char*	AForm::FormNotExecutedException::what() const throw()
{
	return ("The form has not been executed.");
}
