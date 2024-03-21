/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:44:16 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/04 17:32:58 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	return ;
}

RPN::RPN(RPN const & src) : _rpn(src._rpn)
{
	return ;
}

RPN&	RPN::operator=(RPN const & rhs)
{
	this->_rpn = rhs._rpn;
	return *this;
}

RPN::~RPN()
{
	return ;
}

int	operation(char op, int first, int second)
{
	switch (op)
	{
	case '+':
		if (static_cast<long>(first) + static_cast<long>(second) > 2147483647
			|| static_cast<long>(first) + static_cast<long>(second) < -2147483648)
			throw ("Warning : This RPN result in an int overflow.");
		return (first + second);
	case '-':
		if (static_cast<long>(first) - static_cast<long>(second) > 2147483647
			|| static_cast<long>(first) - static_cast<long>(second) < -2147483648)
			throw ("Warning : This RPN result in an int overflow.");
		return (first - second);
	case '*':
		if (static_cast<long>(first) * static_cast<long>(second) > 2147483647
			|| static_cast<long>(first) * static_cast<long>(second) < -2147483648)
			throw ("Warning : This RPN result in an int overflow.");
		return (first * second);
	default:
		if (second == 0)
			throw ("Error : Can not divide by 0.");
		return (first / second);
	}
}

void	RPN::fillAndOp(std::string arg)
{
	int i = 2;
	int	result;
	int	second;

	this->_rpn.push(arg[0] - '0');
	this->_rpn.push(arg[1] - '0');

	while (arg[i] != 0)
	{
		while (ft_isDigit(arg[i])) {
			this->_rpn.push(arg[i++] - '0');
		}
		while (ft_isOp(arg[i]))
		{
			second = this->_rpn.top();
			this->_rpn.pop();
			result = operation(arg[i], this->_rpn.top(), second);
			this->_rpn.pop();
			this->_rpn.push(result);
			i++;
		}
	}
	std::cout << this->_rpn.top() << std::endl;
}
