/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:58:40 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/14 11:31:31 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "string adress            = " << &string << std::endl;
	std::cout << "stringPTR stocked adress = " << stringPTR << std::endl;
	std::cout << "stringREF stocked adress = " << &stringREF << std::endl << std::endl;
	std::cout << "string value             = " << string << std::endl;
	std::cout << "stringPTR pointed value  = " << *stringPTR << std::endl;
	std::cout << "stringREF pointed value  = " << stringREF << std::endl;
	return (0);
}