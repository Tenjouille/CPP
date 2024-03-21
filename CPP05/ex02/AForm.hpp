/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:56:02 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/22 18:56:28 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include <stdlib.h>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

	class	UnsignedFormException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class	OpenIssueException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	void			beSigned(Bureaucrat const & targ);
	virtual void	execute(Bureaucrat const & executor) const = 0;
	
	AForm(std::string const name, int const signable, int const executable);
	AForm();
	AForm(AForm const & targ);
	AForm&	operator=(AForm const & targ);
	virtual ~AForm();

	std::string	getName() const;
	bool		getStatus() const;
	int			getSignable() const;
	int			getExecutable() const;
};

std::ostream&	operator<<(std::ostream& o, AForm const &  targ);

#endif
