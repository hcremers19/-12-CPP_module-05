/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:31:42 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/27 10:58:58 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : _target(src._target)
{
	return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	(void) rhs;

	return (*this);
}

void					RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	try
	{
		// std::cout << executor.getName() << " tried to execute " << getName() << std::endl;
		if (executor.executeForm(*this) == true)
		{
			std::cout << "Drilling noises are being made." << std::endl;

			int	odd = time(NULL) % 2;

			if (odd)
				std::cout << _target << " has successfully been robotomized." << std::endl;
			else
				std::cout << "The robotomy failed." << std::endl;
		}
		else
			throw (FormNotExecutedException());
	}
	catch (FormNotExecutedException& e)
	{
		// std::cout << e.what() << std::endl;
	}
}