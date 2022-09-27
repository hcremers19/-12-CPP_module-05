/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:34:09 by hcremers          #+#    #+#             */
/*   Updated: 2022/09/26 17:57:32 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class 			Bureaucrat;

class 			AForm
{
	public:
		AForm();
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm& src);
		virtual						~AForm();

		AForm&						operator=(const AForm& rhs);

		const std::string			getName() const;
		bool						getSigned() const;
		int							getSignGrade() const;
		int							getExecGrade() const;

		bool						beSigned(const Bureaucrat& bur);
		virtual void				execute(const Bureaucrat& executor) const = 0;

		class	FormNotExecutedException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	private:
		const std::string			_name;
		bool						_signed;
		const int					_signGrade;
		const int					_execGrade;
};

std::ostream&							operator<<(std::ostream& o, AForm const& i);

#endif