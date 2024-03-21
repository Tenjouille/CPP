/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:57:52 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/15 18:58:27 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

# define GREEN = "\033[32m"
# define RED = "\033[31m"
# define YELLOW = "\033[33m"
# define ORANGE = "\033[48:2:255:165:0m%s\033[m"
# define RESET = "\033[0m"

class Harl
{
private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
public:
	void	complain(std::string level);
	Harl(void);
	~Harl(void);
};

#endif