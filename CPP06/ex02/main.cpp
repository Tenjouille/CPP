/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:44:35 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/06 13:09:45 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main()
{
	Base	init;
	init.identify(init);
	init.identify(&init);
	Base*	ptr = init.generate();
	Base&	ref = *ptr;
	ptr->identify(ptr);
	ptr->identify(ref);
	delete ptr;
	return (0);
}


