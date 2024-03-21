/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:46:06 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/18 17:37:12 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
private:
	int					_n;
	static int const	_f = 8;
public:
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	// overloaded operators;
	Fixed&	operator=(Fixed const & rhs);
	bool	operator>(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;
	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;
	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int i);
	Fixed	operator--(int i);
	// min & max
	static const Fixed&	min(Fixed & a, Fixed & b);
	static const Fixed&	max(Fixed & a, Fixed & b);
	static const Fixed&	min(Fixed const & a, Fixed const & b);
	static const Fixed&	max(Fixed const & a, Fixed const & b);
	// constructors & destructors
	Fixed();
	Fixed(Fixed const & src);
	Fixed(int const arg);
	Fixed(float const arg);
	~Fixed();
};

std::ostream &	operator<<(std::ostream& o, Fixed const & i);

#endif
