/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:33:39 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/26 16:55:09 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <sstream>
# include <unistd.h>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <string.h>
# include <list>
# include <vector>
# include <deque>

template<typename T>
int easyfind(T cont, int n)
{
    typename T::iterator   i = std::find(cont.begin(), cont.end(), n);
    
    if (i != cont.end())
        return (std::distance(cont.begin(), i));
    return (-1);
}

#endif