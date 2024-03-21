/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:42:18 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/23 13:40:40 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form"), _status(0), _signable(150), _executable(150)
{
	std::cout << "\033[33mA new form has been created\033[0m" << std::endl;
}

Form::Form(std::string const name, int const signable, int const executable) : _name(name), _status(0), _signable(signable), _executable(executable)
{
	try
	{
		if (signable < 1 || executable < 1)
			throw GradeTooHighException();
		if (signable > 150 || executable > 150)
			throw GradeTooLowException();
		std::cout << "\033[33mA new " << this->_name << " form has been created\033[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[33mAn invalid form named " << this->_name << " has been created : \033[0m" << e.what() << std::endl;
	}	
}

Form::Form(Form const & targ) : _name(targ._name), _status(targ._status), _signable(targ._signable), _executable(targ._executable)
{
	std::cout << "\033[33mA new " << this->_name << " form has been copied pasted from " << targ.getName() << "\033[0m" << std::endl;
}

Form::~Form()
{
	std::cout << "\033[33m" << this->_name << " has been destroyed\033[0m" << std::endl;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char*	Form::InvalidGradeException::what() const throw()
{
	return ("This form occurs to have invalid grades");
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("This form has already been signed");
}

void	Form::beSigned(Bureaucrat const & targ)
{
	if (this->_signable > 150 || this->_signable < 1 || this->_executable > 150 || this->_executable < 1)
		throw InvalidGradeException();
	if (this->_status)
		throw AlreadySignedException();
	if (this->_signable < targ.getGrade())
		throw GradeTooLowException();
	this->_status = true;
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool		Form::getStatus() const
{
	return (this->_status);
}

int			Form::getSignable() const
{
	return(this->_signable);
}

int			Form::getExecutable() const
{
	return(this->_executable);
}

Form&	Form::operator=(Form const & targ)
{
	(void) targ;
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, Form const & targ)
{
	if (targ.getStatus())
		o << targ.getName() << " form minimum grade to sign is [" << targ.getSignable() << "] and to execute is [" << targ.getExecutable() << "]." << std::endl << "The form has already been signed." << std::endl;
	else
		o << targ.getName() << " form minimum grade to sign is [" << targ.getSignable() << "] and to execute is [" << targ.getExecutable() << "]." << std::endl << "The form hasn't been signed yet." << std::endl;
	return (o);
}
