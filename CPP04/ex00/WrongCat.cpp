/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:18:21 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 14:20:03 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void	WrongCat::makeSound(void) const
{
	std::cout << "Anything but MIAAAAAOU !" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
{
	std::cout << "!🐱\tCopy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "!🐱\tDefault constructor called" << std::endl;
	_type = "WrongCat";
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "!🐱\tDestructor called" << std::endl;
	return ;
}
