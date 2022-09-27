/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:35:24 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/27 10:56:15 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "A default Bureaucrat has started working, but they won't be very useful." << std::endl;

	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat " << _name << " has started working." << std::endl;

	try
	{
		_grade = grade;
		if (_grade < 1)
			throw (GradeTooHighException());
		else if (_grade > 150)
			throw (GradeTooLowException());
	}
	catch (GradeTooHighException& e)
	{
		_grade = 1;
		std::cout << "Bureaucrat " << _name << "'s grade was too high, it has been lowered to " << _grade << "." << std::endl;
	}
	catch (GradeTooLowException& f)
	{
		_grade = 150;
		std::cout << "Bureaucrat " << _name << "'s grade was too low, it has been raised to " << _grade << "." << std::endl;
	}

	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade())
{
	return;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " has left the office." << std::endl;

	return;
}

Bureaucrat&				Bureaucrat::operator=(Bureaucrat const& rhs)
{
	_grade = rhs.getGrade();

	return (*this);
}

const std::string		Bureaucrat::getName() const		{return (_name);}
int						Bureaucrat::getGrade() const	{return (_grade);}

void					Bureaucrat::upgrade()
{
	try
	{
		_grade--;
		if (_grade < 1)
			throw (GradeTooHighException());
		else
			std::cout << "Bureaucrat " << _name << " has been upgraded to grade " << _grade << "!" << std::endl;
	}
	catch (GradeTooHighException& e)
	{
		_grade++;
		std::cout << "Bureaucrat " << _name << " already had the best grade, they stayed at grade " << _grade << "." << std::endl;
	}
}

void					Bureaucrat::downgrade()
{
	try
	{
		_grade++;
		if (_grade > 150)
			throw (GradeTooLowException());
		else
			std::cout << "Bureaucrat " << _name << " has been downgraded to grade " << _grade << "." << std::endl;
	}
	catch (GradeTooLowException& e)
	{
		_grade--;
		std::cout << "Bureaucrat " << _name << " already had the worst grade, they stayed at grade " << _grade << "." << std::endl;
	}
}

void					Bureaucrat::signForm(AForm& form) const
{
	try
	{
		// std::cout << getName() << " tried to sign " << form.getName() << std::endl;
		if (form.beSigned(*this) == true)
			std::cout << _name << " signed form " << form.getName() << std::endl;
		else
			throw (GradeTooLowException());
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << _name <<  " couldn't sign form " << form.getName() << " because " << e.what() << std::endl;
	}
}

bool					Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		if (form.getSigned() == true)
		{
			if (_grade <= form.getExecGrade())
			{
				std::cout << _name << " executed " << form.getName() << std::endl;
				return (true);
			}
			else
				throw (GradeTooLowException());
		}
		else
			throw (FormNotSignedException());
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << _name <<  " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return (false);
	}
	catch(const FormNotSignedException& e)
	{
		std::cerr << _name <<  " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return (false);
	}
}

std::ostream&			operator<<(std::ostream& o, Bureaucrat const& i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();

	return (o);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("their grade was too high");
}
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("their grade was too low");
}
const char*	Bureaucrat::FormNotSignedException::what() const throw()
{
	return ("the form wasn't signed");
}