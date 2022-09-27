/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:31:42 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/26 16:48:00 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : _target(src._target)
{
	return;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	(void) rhs;

	return (*this);
}

void					PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	try
	{
		// std::cout << executor.getName() << " tried to execute " << getName() << std::endl;
		if (executor.executeForm(*this) == true)
		{
			std::cout << _target << " has been forgiven by Zaphod Beeblebrox." << std::endl;
		}
		else
			throw (FormNotExecutedException());
	}
	catch (FormNotExecutedException& e)
	{
		// std::cout << e.what() << std::endl;
	}
}