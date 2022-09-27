/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:07:26 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/27 13:12:07 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	return;
}

Intern::Intern(const Intern& src)
{
	*this = src;

	return;
}

Intern::~Intern()
{
	return;
}

Intern&	Intern::operator=(const Intern& rhs)
{
	(void)rhs;

	return (*this);
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	int			i;
	AForm		*ret;
	std::string	forms[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	
	for (i = 0; i < 3 && form != forms[i]; i++);

	switch (i)
	{
		case (0):
			ret = new RobotomyRequestForm(target);
			std::cout << "Intern created " << ret->getName() << std::endl;
			break;
		case (1):
			ret = new ShrubberyCreationForm(target);
			std::cout << "Intern created " << ret->getName() << std::endl;
			break;
		case (2):
			ret = new PresidentialPardonForm(target);
			std::cout << "Intern created " << ret->getName() << std::endl;
			break;
		default:
			ret = NULL;
			std::cout << "Intern didn't understand which form they had to create" << std::endl;
	}

	return(ret);
}
