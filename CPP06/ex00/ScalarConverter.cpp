/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:36:12 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/06 13:58:39 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs)
{
	(void) rhs;
	return (*this);
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	(void) src;
}

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

std::string	commaDisplay(std::string str)
{
	size_t	pos = str.find(".");
	if (pos++ == std::string::npos && str.length() < 7)
		return (".0");
	if (pos > 5)
		return ("");
	while (str[pos] == '0')
		pos++;
	if (str[pos] && str[pos] != 'f')
		return ("");
	return (".0");
}

void	convFromChar(char c)
{
	if (c < ' ')
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << "\nfloat: " << static_cast<float>(c) << ".0f\ndouble: " << static_cast<double>(c) << ".0" << std::endl;
}

void	convFromInt(int n, std::string str)
{
	if (n && (n < ' ' || n == 127))
		std::cout << "char: Non displayable" << std::endl;
	else if (n > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << "\nfloat: " << static_cast<float>(n) << commaDisplay(str) << "f\ndouble: " << static_cast<double>(n) << commaDisplay(str) << std::endl;
}

void	convFromDouble(double n, std::string str)
{
	if (n && (n < ' ' || n == 127))
		std::cout << "char: Non displayable" << std::endl;
	else if (n > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	if (n > 2147483647 || n < -2147483648)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << static_cast<float>(n) <<  commaDisplay(str) << "f\ndouble: " << n << commaDisplay(str) << std::endl;
}

void	convFromFloat(float n, std::string str)
{
	if (n && (n < ' ' || n == 127))
		std::cout << "char: Non displayable" << std::endl;
	else if (n > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	if (n >= 2147483648 || n < -2147483648)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << n <<  commaDisplay(str) << "f\ndouble: " << static_cast<double>(n) << commaDisplay(str) << std::endl;
}

int	findType(std::string str)
{
	int		i = 0;
	int 	count = 0;
	char	*endptr;
	
	if (str == "+inf" || str == "-inf" || str == "nan")
		return (5);
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return (4);
	if ((str.length() == 1 && (str[0] < '0' || str[0] > '9')) || !str[0])
		return (0);
	if (str[0] == '+' || str[0] == '-')
	{
		i++;
		if (str[i] && (str[i] < '0' || str[i] > '9'))
			return (-1);	
	}
	while (str[i])
	{
		while (str[i] <= '9' && str[i] >= '0')
			i++;
		if (str[i] == 'f')
		{
			if (str[i + 1])
				return (-1);
			return (2);
		}
		if (str[i] == '.')
		{
			if (count || !str[i + 1] || str[i + 1] == 'f' || i == 0) 
				return (-1);
			count++;
			i++;
		}
		else if (str[i])
			return (-1);
	}
	
	double	dbl = std::strtod(str.c_str(), &endptr);

	if (*endptr != '\0')
		return (-1);
	if (count == 1 || dbl > 2147483647 || dbl < -2147483648)
		return (3);
	return (1);
}

void	ScalarConverter::convert(std::string str)
{
	int		type = findType(str);

	switch (type)
	{
	case -1:
		std::cout << "This litteral is invalid" << std::endl; 
		break;
	case 0:
		convFromChar(str[0]);
		break;		
	case 1:
		convFromInt(static_cast<int>(std::strtod(str.c_str(), NULL)), str);
		break;
	case 2:
		convFromFloat(std::strtof(str.c_str(), NULL), str);
		break;
	case 3:
		convFromDouble(std::strtod(str.c_str(), NULL), str);
		break;
	case 4:
		std::cout << "char: impossible\nint: impossible\nfloat: " << str << "\ndouble: ";
		if (str[0] == 'n')
			std::cout << str[0] << str[1] << str[2] << std::endl;
		else
			std::cout << str[0] << str[1] << str[2] << str[3] << std::endl;
		break;
	case 5:
		std::cout << "char: impossible\nint: impossible\nfloat: " << str << "f\ndouble: " << str << std::endl;
		break;
	default:
		break;
	}
}