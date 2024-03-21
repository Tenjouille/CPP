/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:44:16 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/04 16:47:15 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <unistd.h>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <string.h>
# include <stack>

class RPN
{
private:
    std::stack<int> _rpn;
public:
    RPN();
    RPN(RPN const & src);
    RPN& operator=(RPN const & hrs);
    ~RPN();
    void    fillAndOp(std::string arg);
};

int	ft_isDigit(char c);
int	ft_isOp(char c);

#endif

