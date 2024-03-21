/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:32:37 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/23 12:18:07 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Miserable bureaucrate"), _grade(150)
{
	std::cout << "\033[32mA new bureaucrat has been hired\033[0m" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[31m" << this->_name << " has been fired\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
	std::cout << "\033[32m" << this->_name << " has been copied from " << src._name << "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, long long const grade) : _name(name)
{
	try
	{
		if (grade < 1)
		{
			this->_grade = 1;
			throw GradeTooHighException();
		}
		if (grade > 150)
		{
			this->_grade = 150;
			throw GradeTooLowException();
		}
		this->_grade = grade;
		std::cout << "\033[32m" << this->_name << " has been hired\033[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << " His grade has been set to its closer valid grade." << std::endl;
	}
}

std::string	Bureaucrat::getName() const
{
	return(this->_name);
}

long long	Bureaucrat::getGrade() const
{
	return(this->_grade);
}


void	Bureaucrat::incrGrade(void)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw GradeTooHighException();
		this->_grade--;
		std::cout << this->_name << "'s grade has been increased" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	Bureaucrat::decrGrade(void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw GradeTooHighException();
		this->_grade++;
		std::cout << this->_name << "'s grade has been decreased" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("This Bureaucrat has a too high grade !");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("This Bureaucrat has a too low grade !");
}


Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat const & targ)
{
	o << targ.getName() << ", bureaucrat grade " << targ.getGrade() << "." << std::endl;
	return (o);
}
