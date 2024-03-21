/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:41:10 by tbourdea          #+#    #+#             */
/*   Updated: 2024/01/31 14:51:37 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <cfloat>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const & src);
    ScalarConverter& operator=(ScalarConverter const & hrs);
    ~ScalarConverter();
public:
    static void  convert(std::string str);
};

#endif

