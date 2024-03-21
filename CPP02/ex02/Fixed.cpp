/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:46:01 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/19 12:00:26 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

float	Fixed::toFloat(void) const
{
	return((float)this->_n / (float)(1 << _f));
}

int		Fixed::toInt(void) const
{
	return(this->_n >> _f);
}

int	Fixed::getRawBits(void) const
{
	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_n = rhs._n;
	return (*this);
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	Fixed	res(this->toFloat() + rhs.toFloat());
	return (res);
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	Fixed	res(this->toFloat() - rhs.toFloat());
	return (res);
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	Fixed	res(this->toFloat() * rhs.toFloat());
	return (res);
}


Fixed	Fixed::operator/(Fixed const & rhs) const
{
	Fixed	res(this->toFloat() / rhs.toFloat());
	return (res);
}


Fixed&	Fixed::operator++(void)
{
	this->_n++;
	return (*this);
}


Fixed&	Fixed::operator--(void)
{
	this->_n--;
	return (*this);
}

Fixed	Fixed::operator++(int i)
{
	Fixed	res = *this;
	if (!i)
		i = 1;
	this->_n += i;
	return (res);
}

Fixed	Fixed::operator--(int i)
{
	Fixed	res = *this;
	if (!i)
		i = 1;
	this->_n -= i;
	return (res);
}

const Fixed&	Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(Fixed & a, Fixed & b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed&	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return (b);
	return (a);
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return ;
}

Fixed::Fixed(void) : _n(0)
{
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed::Fixed(int const arg) : _n(arg << _f)
{
	return ;
}

Fixed::Fixed(float const arg) : _n(roundf(arg * (1 << _f)))
{
	return ;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();

	return (o);
}