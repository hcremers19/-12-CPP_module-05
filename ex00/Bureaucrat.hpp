/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:34:09 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/22 15:53:02 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();

		Bureaucrat&			operator=(const Bureaucrat& rhs);

		const std::string	getName() const;
		int					getGrade() const;

		void				upgrade();
		void				downgrade();

		class 				GradeTooHighException : public std::exception {};
		class 				GradeTooLowException : public std::exception {};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&				operator<<(std::ostream& o, const Bureaucrat& i);

#endif