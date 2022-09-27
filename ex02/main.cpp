/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:33:52 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/27 12:18:23 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// using namespace std;

int	main(void)
{
	Bureaucrat				mike("Michael", 1);
	Bureaucrat				dewy("Dwight", 150);
	// AForm					zero("101", 1, 1);
	ShrubberyCreationForm	one("forest");
	RobotomyRequestForm		two("Marvin");
	PresidentialPardonForm	three("Arthur Dent");

	std::cout << std::endl;
	std::cout << one;
	std::cout << two;
	std::cout << three;

	std::cout << std::endl;
	one.execute(dewy);
	dewy.signForm(one);
	
	std::cout << std::endl;
	mike.signForm(one);
	mike.signForm(two);
	mike.signForm(three);
	
	std::cout << std::endl;
	one.execute(dewy);
	
	std::cout << std::endl;
	one.execute(mike);
	two.execute(mike);
	three.execute(mike);
	
	std::cout << std::endl;
	std::cout << one;
	std::cout << two;
	std::cout << three;

	std::cout << std::endl;

	return (0);
}
