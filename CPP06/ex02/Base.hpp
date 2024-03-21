/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:44:35 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/31 22:20:42 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <sstream>
# include <unistd.h>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <ctime>
# include <string.h>

class A;
class B;
class C;

class Base
{
public:
    Base();
    virtual ~Base();

    virtual Base*   generate(void) const;
    virtual void    identify(Base* p) const;
    virtual void    identify(Base& p) const;
};

#endif

