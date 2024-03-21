/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:44:16 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/04 17:27:33 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	ft_isDigit(char c)
{
	if (c >= '0' && c <='9')
		return (1);
	return (0);
}

int	ft_isOp(char c)
{
	if (c == '+' ||  c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

void	parsing(std::string arg)
{
	int	digit = 0;
	int	op = 0;
	int	i = 0;

	for (size_t it = 0; it < arg.size(); it++)
	{
		if (arg[it] != ' ' && arg[it + 1] && arg[it + 1] != ' ')
			throw ("Error : RPN synthax error");
		if (!ft_isDigit(arg[it]) && !ft_isOp(arg[it]) && arg[it] != ' ')
			throw ("Error : RPN synthax error");
		digit += ft_isDigit(arg[it]);
		op += ft_isOp(arg[it]);
	}
	while (arg[i] == ' ')
		i++;
	if (ft_isOp(arg[i]))
		throw ("Error : RPN has postfix operators");
	i = arg.size() - 1;
	while (arg[i] == ' ')
		i--;
	if (ft_isDigit(arg[i]))
		throw ("Error : RPN has postfix operators");
	if (digit != op + 1)
		throw ("Error : Should be one operator less than digits");
}

void	eraseSpaces(std::string& arg)
{
	while (arg.find(' ') != std::string::npos)
		arg.erase(arg.find(' '), 1);
	if (ft_isOp(arg[0]) || ft_isOp(arg[1]))
		throw ("Error : Two first elements must be two digits");
}

int	main(int ac, char **av)
{
	RPN	rpn;

	if (ac != 2) {
		std::cout << "Error : This program needs a RPN past as a single argument." << std::endl;
		return (1);
	}
	std::string	arg = av[1];
	try
	{
		parsing(arg);
		eraseSpaces(arg);
		rpn.fillAndOp(arg);
	}
	catch(const char* msg)
	{
		std::cerr << msg << '\n';
	}
	
	return (0);
}


