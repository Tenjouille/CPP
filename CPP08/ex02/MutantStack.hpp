/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:39:12 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/01 12:17:37 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <list>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
private:
public:
    MutantStack(){}
    MutantStack(MutantStack const & src) : std::stack<T>(src) {}
    MutantStack& operator=(MutantStack const & hrs)
    {
        std::stack<T>::operator=(hrs);
        return (*this);
    }
    ~MutantStack() {}

    typedef typename  std::stack<T>::container_type::iterator  iterator;
    typedef typename  std::stack<T>::container_type::const_iterator  const_iterator;
    typedef typename  std::stack<T>::container_type::reverse_iterator  reverse_iterator;
    typedef typename  std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;
    
    iterator                begin() {return (std::stack<T>::c.begin());}
    iterator                end() {return (std::stack<T>::c.end());}
    const_iterator          begin() const {return (std::stack<T>::c.cbegin());}
    const_iterator          end() const {return (std::stack<T>::c.cend());}
    reverse_iterator        rbegin() {return (std::stack<T>::c.rbegin());}
    reverse_iterator        rend() {return (std::stack<T>::c.rend());}
    const_reverse_iterator  rbegin() const {return (std::stack<T>::c.crbegin());}
    const_reverse_iterator  rend() const {return (std::stack<T>::c.crend());}
};


#endif

