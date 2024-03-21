/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:42:18 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/22 17:40:19 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Form"), _status(0), _signable(150), _executable(150)
{
	std::cout << "\033[33mA new form has been created\033[0m" << std::endl;
}

AForm::AForm(std::string const name, int const signable, int const executable) : _name(name), _status(0), _signable(signable), _executable(executable)
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
		std::cerr << e.what() << '\n';
	}	
}

AForm::AForm(AForm const & targ) : _name(targ._name), _status(targ._status), _signable(targ._signable), _executable(targ._executable)
{
	std::cout << "\033[33mA new " << this->_name << " form has been copied pasted from " << targ.getName() << "\033[0m" << std::endl;
}

AForm::~AForm()
{
	std::cout << "\033[33m" << this->_name << " has been destroyed\033[0m" << std::endl;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char*	AForm::InvalidGradeException::what() const throw()
{
	return ("This form occurs to have invalid grades");
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return ("This form has already been signed");
}

const char*	AForm::UnsignedFormException::what() const throw()
{
	return ("This form hasn't been signed yet");
}

const char*	AForm::OpenIssueException::what() const throw()
{
	return ("Shruberry field's creation failed");
}

void	AForm::beSigned(Bureaucrat const & targ)
{
	if (this->_signable < targ.getGrade())
		throw GradeTooLowException();
	if (this->_signable > 150 || this->_signable < 1 || this->_executable > 150 || this->_executable < 1)
		throw InvalidGradeException();
	if (this->_status)
		throw AlreadySignedException();
	this->_status = true;
}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool		AForm::getStatus() const
{
	return (this->_status);
}

int			AForm::getSignable() const
{
	return(this->_signable);
}

int			AForm::getExecutable() const
{
	return(this->_executable);
}

AForm&	AForm::operator=(AForm const & targ)
{
	(void) targ;
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, AForm const & targ)
{
	if (targ.getStatus())
		o << targ.getName() << " form minimum grade to sign is [" << targ.getSignable() << "] and to execute is [" << targ.getExecutable() << "]." << std::endl << "The form has already been signed." << std::endl;
	else
		o << targ.getName() << " form minimum grade to sign is [" << targ.getSignable() << "] and to execute is [" << targ.getExecutable() << "]." << std::endl << "The form hasn't been signed yet." << std::endl;
	return (o);
}
