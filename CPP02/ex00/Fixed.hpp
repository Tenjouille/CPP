/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:59:21 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/19 11:59:22 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
private:
	int					_n;
	static int const	_f;
public:
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed&	operator=(Fixed const & rhs);
	Fixed(Fixed const & src);
	Fixed();
	~Fixed();
};

#endif
