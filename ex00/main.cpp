/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:33:52 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/23 16:09:40 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// using namespace std;

int	main(void)
{
	Bureaucrat	mike("Michael", 1);
	Bureaucrat	jims("Jim", 0);
	Bureaucrat	dewy("Dwight", 150);
	Bureaucrat	andy("Andy", 160);

	std::cout << std::endl;
	mike.downgrade();
	mike.upgrade();
	mike.upgrade();

	std::cout << std::endl;
	dewy.upgrade();
	dewy.downgrade();
	dewy.downgrade();

	std::cout << std::endl;
	std::cout << mike << std::endl;;
	std::cout << jims << std::endl;;
	std::cout << dewy << std::endl;;
	std::cout << andy << std::endl;;

	std::cout << std::endl;
	return (0);
}
