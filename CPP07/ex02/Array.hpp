/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:50:08 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/07 17:01:20 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <sstream>
# include <unistd.h>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <string.h>
# include <exception>


template<typename T>
class Array
{
private:
    T*              _array;
    unsigned int    _size;
public:
    Array();
    Array(unsigned int n);
    Array(Array const & src);
    ~Array();

    class OutOfBoundException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    
    Array&  operator=(Array const & hrs);
    T&      operator[](unsigned int const idx) const;
    unsigned int    size() const;
};

#endif

