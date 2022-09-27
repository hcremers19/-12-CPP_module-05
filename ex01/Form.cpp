/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:41:27 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/26 15:52:32 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _signGrade(1), _execGrade(1)
{
	std::cout << "Form " << _name << " has been created." << std::endl;

	return;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "Form " << _name << " has been created." << std::endl;

	return;
}

Form::Form(const Form& src) : _name(src.getName()), _signed(src.getSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	return;
}

Form::~Form()
{
	return;
}

Form&				Form::operator=(const Form& rhs)
{
	_signed = rhs.getSigned();													// No other non-const attributes in the class

	return (*this);
}

const std::string	Form::getName() const		{return (_name);}
bool				Form::getSigned() const		{return (_signed);}
int					Form::getSignGrade() const	{return (_signGrade);}
int					Form::getExecGrade() const	{return (_execGrade);}

bool				Form::beSigned(const Bureaucrat& bur)
{
	try
	{
		if (bur.getGrade() > _signGrade)
			throw (Form::GradeTooLowException());
		else
		{
			_signed = true;
			std::cout << "Form " << _name << " has been signed by " << bur.getName() << std::endl;
			return (true);
		}
	}
	catch(const Form::GradeTooLowException& e)
	{
		return (false);
	}

	return (false);
}

std::ostream&		operator<<(std::ostream& o, const Form& i)
{
	o << "Form: " << i.getName() << std::endl;
	o << "Status: ";
	
	if (i.getSigned() == true)
		o << "signed" << std::endl;
	else
		o << "not signed" << std::endl;

	o << "Required grade to sign: " << i.getSignGrade() << std::endl;
	o << "Required grade to execute: " << i.getExecGrade() << std::endl;

	return (o);
}
