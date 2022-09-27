/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:34:09 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/26 15:28:23 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& src);
		~Bureaucrat();

		Bureaucrat&			operator=(Bureaucrat const& rhs);

		const std::string	getName() const;
		int					getGrade() const;

		void				upgrade();
		void				downgrade();
		void				signForm(Form& form);

		class 				GradeTooHighException : public std::exception {};
		class 				GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("their grade was too low");
				}
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&				operator<<(std::ostream& o, Bureaucrat const& i);

#endif