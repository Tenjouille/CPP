/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:13:14 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/23 12:06:14 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("target")
{
	std::cout << "\033[42mA default RRF has been printed\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[42mA new RRF has been printed, targeting "<< target << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & targ) : AForm("RobotomyRequestForm", 72, 45), _target(targ._target)
{
	std::cout << "\033[42mA new RRF has been printed, from the one targeting "<< targ._target << "\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[42mRRF targeting "<< this->_target << " has been removed\033[0m" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & targ)
{
	this->_target = targ._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::srand(time(NULL));
	int	random = std::rand();

	if (this->getStatus() == false)
		throw UnsignedFormException();
	if (executor.getGrade() > this->getExecutable())
		throw GradeTooLowException();
	std::cout << "DzDzzzzzzzzt... " << std::endl;
	if (random % 2)
		std::cout << this->_target << " has been robotomised with success !"  << std::endl;
	else
		std::cout << "*Clang* !! " << this->_target << " robotomisation just failed !" << std::endl;
}