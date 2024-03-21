/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:45:37 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/18 16:45:38 by tbourdea         ###   ########.fr       */
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
	Fixed();
	Fixed(Fixed const & src);
	Fixed(int const arg);
	Fixed(float const arg);
	~Fixed();
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed&	operator=(Fixed const & rhs);
	
};

std::ostream &	operator<<(std::ostream& o, Fixed const & i);

#endif
