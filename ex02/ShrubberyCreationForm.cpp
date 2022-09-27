/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:14:39 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/27 11:22:50 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : _target(src._target)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

ShrubberyCreationForm& 	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	(void)rhs;

	return (*this);
}

void					ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	try
	{
		// std::cout << executor.getName() << " tried to execute " << getName() << std::endl;
		if (executor.executeForm(*this) == true)
		{
			std::ofstream	ofs(_target + "_shrubbery", std::ios_base::app);
			ofs << TREE << std::endl;
		}
		else
			throw (FormNotExecutedException());
	}
	catch (FormNotExecutedException& e)
	{
		// std::cout << e.what() << std::endl;
	}
	return;
}
