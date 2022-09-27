/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:34:09 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/26 15:52:09 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form& src);
		~Form();

		Form&				operator=(const Form& rhs);

		const std::string	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		bool				beSigned(const Bureaucrat& bur);

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
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream&				operator<<(std::ostream& o, const Form& i);

#endif