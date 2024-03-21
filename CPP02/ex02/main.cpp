/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:46:10 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/19 12:01:00 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(a);
	std::cout <<"a = " << a << std::endl;
	std::cout <<"++a = " << ++a << std::endl;
	std::cout <<"a = " << a << std::endl;
	std::cout <<"a++ = " << a++ << std::endl;
	std::cout <<"a = " << a << std::endl;
	std::cout <<"b = " << b << std::endl;
	std::cout <<"a + b = " << a + b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	while (a < b + 1)
		a++;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout <<"a = " << a << std::endl;
	while (a != b)
		a--;
	std::cout <<"a = " << a << std::endl;
	std::cout <<"b = " << b << std::endl;
	while (a > 1)
		--a;
	std::cout <<"a = " << a << std::endl;
	std::cout <<"a * b = " << a * b << std::endl;
	std::cout <<"b / b = " << b / b << std::endl;
	std::cout <<"c = " << c << std::endl;
	std::cout << Fixed::max(b, c) << std::endl;
	std::cout << Fixed::min(c, b) << std::endl;
	std::cout <<"c - b = " << c - b << std::endl;
	while (a > 0)
		a--;
	if (a == c)
		return (42);
	return (0);
}
