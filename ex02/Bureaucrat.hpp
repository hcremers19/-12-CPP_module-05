/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:34:09 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/27 10:55:40 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class 			AForm;

class 			Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& src);
		~Bureaucrat();

		Bureaucrat&					operator=(Bureaucrat const& rhs);

		const std::string			getName() const;
		int							getGrade() const;

		void						upgrade();
		void						downgrade();
		void						signForm(AForm& form) const;
		bool						executeForm(const AForm& form) const;

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class	FormNotSignedException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	private:
		const std::string			_name;
		int							_grade;
};

std::ostream&						operator<<(std::ostream& o, Bureaucrat const& i);

#endif