/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:33:52 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/27 13:16:08 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

int	main(void)
{
	Intern	pete;
	AForm*	zero;
	AForm*	one;
	AForm*	two;
	AForm*	three;

	std::cout << std::endl;
	zero = pete.makeForm("form", "zero");

	std::cout << std::endl;
	one = pete.makeForm("shrubbery creation", "garden");

	std::cout << std::endl;
	two = pete.makeForm("robotomy request", "Bender");

	std::cout << std::endl;
	three = pete.makeForm("presidential pardon", "Percival");

	std::cout << std::endl;

	return (0);
}
