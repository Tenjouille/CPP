/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:44:35 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/06 13:12:46 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
	std::cout << "Default constructor called for Base" << std::endl;
}

Base::~Base()
{
	std::cout << "Destructor called for Base" << std::endl;
}

Base*	Base::generate(void) const
{
	int	random;
	
	srand(time(NULL));
	random = rand() % 3;
	switch (random)
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	default:
		return (new C());
	}
}

void	Base::identify(Base* p) const
{
	A*	a = dynamic_cast<A*>(p);
	B*	b = dynamic_cast<B*>(p);
	C*	c = dynamic_cast<C*>(p);
	
	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
	else
		std::cout << "\033[33mNo class A, B or C has been generated from Base*\033[0m" << std::endl;
}

void	Base::identify(Base& p) const
{
	try
	{
		A	a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(std::exception &e)
	{
	}
	try
	{
		B	b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(std::exception &e)
	{
	}
	try
	{
		C	c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(std::exception &e)
	{
	}
	std::cout << "\033[31mNo class A, B or C has been generated from Base&\033[0m" << std::endl;
}
