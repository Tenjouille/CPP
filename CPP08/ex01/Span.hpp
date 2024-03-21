/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:11:28 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/05 11:26:30 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <cmath>
# include <cstdlib>
# include <exception>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <string>
# include <string.h>
# include <unistd.h>
# include <vector>

class Span
{
private:
    std::vector<int>    _span;
    size_t              _size;
public:
//  CANONIC FORM
    Span();
    Span(size_t n);
    Span(Span const & src);
    ~Span();
    
    Span& operator=(Span const & hrs);

//  METHODS    
    void    addNumber(int n);
    void	addNumber(std::vector<int> moreValues);
    int     shortestSpan();
    int     longestSpan();
    void    print();

//  EXCEPTIONS
    class NoDiffException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class FullSpanException : public std::exception
    {
    public:
        const char* what() const throw();
    };
    
};

#endif

