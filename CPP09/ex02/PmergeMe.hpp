/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:28:03 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/20 13:26:05 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cmath>
# include <cstdlib>
# include <deque>
# include <fstream>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <vector>

class PmergeMe
{
private:
    std::vector<int>    _vec;
    std::deque<int>     _deq;
public:
    PmergeMe();
    PmergeMe(PmergeMe const & src);
    ~PmergeMe();

    PmergeMe&           operator=(PmergeMe const & hrs);

    void                execution();
    void                parsing(int ac, char **av);
    size_t              jacobsthal(size_t n);
    template <typename T>
    void	            mergeInsert(T &main, T &insert);
    template <typename T>
    void	            dichotomy(T &main, int element);
    template <typename T>
    void            	fordJohnson(T &toSort);
};


#endif

