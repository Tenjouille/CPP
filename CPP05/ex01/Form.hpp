/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:56:02 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/18 16:47:40 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	bool				_status;
	int const			_signable;
	int const			_executable;
public:
	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class   GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class	InvalidGradeException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class	AlreadySignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	void	beSigned(Bureaucrat const & targ);
	
	Form(std::string const name, int const signable, int const executable);
	Form();
	Form(Form const & targ);
	Form&	operator=(Form const & targ);
	~Form();

	std::string	getName() const;
	bool		getStatus() const;
	int			getSignable() const;
	int			getExecutable() const;
};

std::ostream&	operator<<(std::ostream& o, Form const &  targ);

#endif
