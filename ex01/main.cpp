/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:33:52 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/26 15:24:29 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// using namespace std;

int	main(void)
{
	Bureaucrat	mike("Michael", 1);
	Bureaucrat	dewy("Dwight", 150);
	Form		one("101", 1, 1);
	Form		two("202", 150, 150);

	std::cout << std::endl;
	std::cout << one;

	std::cout << std::endl;
	std::cout << two;

	std::cout << std::endl;
	dewy.signForm(one);

	std::cout << std::endl;
	mike.signForm(one);

	std::cout << std::endl;
	dewy.signForm(two);

	std::cout << std::endl;
	std::cout << one;

	std::cout << std::endl;
	std::cout << two;

	std::cout << std::endl;

	return (0);
}
