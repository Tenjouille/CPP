/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:08:31 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/28 18:36:37 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShruberryCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

# include <iostream>
# include <sstream>
# include <unistd.h>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <string.h>

class Intern
{
public:

    Intern();
    Intern(Intern const & src);
    Intern& operator=(Intern const & hrs);
    ~Intern();

    AForm   *makeForm(std::string name, std::string target);

    class InvalidNameException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif
