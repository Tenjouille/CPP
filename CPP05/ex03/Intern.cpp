/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:08:31 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/28 18:36:52 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default constructor called for Intern" << std::endl;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Copy constructor called for Intern" << std::endl;
	(void) src;
}

Intern&	Intern::operator=(Intern const & rhs)
{
	std::cout << "Assignment operator called for Intern" << std::endl;
	(void) rhs;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Destructor called for Intern" << std::endl;
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string	Form[3] = {"ShruberryCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	std::cout << "Intern creates ";
	int	tab = -1;
	for(int i = 0; i < 3 ; i++)
		if (Form[i] == name)
			tab = i;
	switch (tab)
	{
	case 0:
		std::cout << "a new SCF." << std::endl;
		return (new ShruberryCreationForm(target));
	case 1:
		std::cout << "a new RRF." << std::endl;
		return (new RobotomyRequestForm(target));
	case 2:
		std::cout << "a new PPF." << std::endl;
		return (new PresidentialPardonForm(target));
	default:
		throw InvalidNameException();
	}
	
}

const char*	Intern::InvalidNameException::what() const throw()
{
	return ("an invalid form. The form creation has been interupted");
}