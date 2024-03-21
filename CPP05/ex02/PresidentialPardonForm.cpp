/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:33:01 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/23 12:06:57 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("target")
{
	std::cout << "\033[42mA default PPF has been printed\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\033[42mA new PPF has been printed, targeting "<< target << "\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & targ) : AForm("PresidentialPardonForm", 25, 5), _target(targ._target)
{
	std::cout << "\033[42mA new PPF has been printed, from the one targeting "<< targ._target << "\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[42mPPF targeting "<< this->_target << " has been removed\033[0m" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & targ)
{
	this->_target = targ._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getStatus() == false)
		throw UnsignedFormException();
	if (executor.getGrade() > this->getExecutable())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
