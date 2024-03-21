/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:33:49 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/06 18:15:13 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : A_Materia("cure")
{
	return ;
}

Cure::Cure(Cure const & src) : A_Materia(src._type)
{
	return ;
}

Cure::~Cure(void)
{
	return ;
}

Cure&	Cure::operator=(Cure const & cpy)
{
	if (this != &cpy)
		this->_type = cpy._type;
	return(*this);
}

A_Materia*	Cure::clone(void) const
{
	A_Materia*	clone = new Cure();
	return (clone);
}

void	Cure::use(I_Character& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}