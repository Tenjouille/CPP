/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:46:42 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/31 19:37:06 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

# include <iostream>
# include <sstream>
# include <unistd.h>
# include <string>
# include <cstdlib>
# include <stdint.h>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <string.h>

class Serializer
{
private:
    Serializer();
    Serializer(Serializer const & src);
    Serializer& operator=(Serializer const & hrs);
    ~Serializer();
public:
    static uintptr_t    serialize(t_Data* ptr);
    static t_Data*        deserialize(uintptr_t raw);
};

#endif

