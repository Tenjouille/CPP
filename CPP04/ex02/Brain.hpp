/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:31:14 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/21 20:46:59 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string	_ideas[100];
public:
	
    //Cannonic Form
    Brain();
    Brain(Brain const & src);
    virtual ~Brain();

    Brain& operator=(Brain const & hrs);
};

# endif