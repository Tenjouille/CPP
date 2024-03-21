/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:36:04 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/06 18:29:52 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <sstream>
# include <unistd.h>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <string.h>

template<typename T>
void    swap(T& a, T& b)
{
    T   tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T   min(T const & a, T const & b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T   max(T const & a, T const & b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif

