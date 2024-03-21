/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:27 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 21:32:13 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain&	Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
		for(int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

Brain::Brain(Brain const & src)
{
	std::cout << "🧠\tCopy constructor called" << std::endl;
		for(int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	return ;
}

Brain::Brain()
{
	std::cout << "🧠\tDefault constructor called" << std::endl;
	return ;
}

Brain::~Brain()
{
	std::cout << "🧠\tDestructor called" << std::endl;
	return ;
}
