/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:33:47 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/22 17:38:22 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : A_Materia("ice")
{
	return ;
}

Ice::Ice(Ice const & src) : A_Materia(src._type)
{
	return ;
}

Ice::~Ice(void)
{
	return ;
}

Ice&	Ice::operator=(Ice const & cpy)
{
	if (this != &cpy)
		this->_type = cpy._type;
	return(*this);
}

A_Materia*	Ice::clone(void) const
{
	A_Materia*	clone = new Ice();
	return (clone);
}

void	Ice::use(I_Character& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}