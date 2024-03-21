/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:38:13 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/15 19:08:59 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	harl;

	std::cout << "\033[32m" << "When Harl tries to DEBUG your code : " << "\033[0m";
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "\033[33m" << "When Harl has an INFO to tell you : " << "\033[0m";
	harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "\e[38;5;208m" << "When Harl tries to WARN you about something : " << "\033[0m";
	harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "\033[31m" << "When Harl finds an ERROR your code : " << "\033[0m";
	harl.complain("ERROR");
	std::cout << std::endl;
	std::cout << "When Harl wants to eat PASTAS : " << "\033[0m";
	harl.complain("PASTA");
	std::cout << std::endl;
}