/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:28:03 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/20 13:42:00 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe(PmergeMe const & src) : _vec(src._vec), _deq(src._deq)
{
	return ;
}

PmergeMe&	PmergeMe::operator=(PmergeMe const & rhs)
{
	_vec = rhs._vec;
	_deq = rhs._deq;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	return ;
}

int	ft_atoi(char *str)
{
	int			i = 0;
	int			k;
	std::string	err = str;

	k = 0;
	if (str[i] == '+')
		i++;
	while (isdigit(str[i]))
	{
		if ((static_cast<unsigned long>(k) * 10 + str[i] - '0') > 2147483647)
			throw ("Error : " + err + " is bigger than a positive integer");
		k = k * 10 + str[i] - '0';
		i++; 
	}
	if (str[i])
		throw ("Error : " + err + " is not a positive integer.");
	return (k);
}

void	PmergeMe::parsing(int ac, char **av)
{
	if (ac <= 2)
		throw (static_cast<std::string>("Error : You need to enter at least 2 positive integer to use PmergeMe."));
	for (int i = 1; av[i]; i++)
		_vec.push_back(ft_atoi(av[i]));
	for (int i = 1; av[i]; i++)
		_deq.push_back(ft_atoi(av[i]));
}

size_t	PmergeMe::jacobsthal(size_t n)
{
	if (n < 2)
		return (n);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

template <typename T>
void	PmergeMe::dichotomy(T &big, int element)
{
	int	max = big.size() - 1;
	int	min = 0;
	
	while (min <= max)
	{
		int	mid = min + (max - min) / 2;
		if (big[mid] < element)
			min = mid + 1;
		else
			max = mid - 1;
	}
	big.insert(big.begin() + min, element);
}


template <typename T>
void	PmergeMe::mergeInsert(T &big, T &small)
{
	size_t	sizeMax = small.size();

	for(size_t idx = 0; idx < sizeMax; idx++)
	{
		size_t	sortIdx = 0;
		size_t jkb = 0;
		while (jacobsthal(jkb) < idx)
			jkb++;
		if (jkb)
		{
			if (jacobsthal(jkb) >= sizeMax - 1)
				sortIdx = sizeMax - (idx - jacobsthal(jkb - 1));
			else
				sortIdx = jacobsthal(jkb) + 1 - (idx - jacobsthal(jkb - 1));
		}
		dichotomy(big, small[sortIdx]);
	}
}


template<typename T>
void	PmergeMe::fordJohnson(T &toSort)
{
	T	small;
	T	big;

	for (size_t it = 0; it < toSort.size() - 1; it += 2)
		if (toSort[it] > toSort[it + 1])
			std::swap(toSort[it], toSort[it + 1]);
	if (toSort.size() <= 2)
		return ;
	for (size_t it = 0; it < toSort.size(); it += 2)
	{
		small.push_back(toSort[it]);
		if (it < toSort.size() - 1)
			big.push_back(toSort[it + 1]);
	}
	fordJohnson(big);
	mergeInsert(big, small);
	toSort = big;
}

unsigned long long	getTime()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	PmergeMe::execution()
{
	std::cout << "Before:";
	for(size_t it = 0; it != _vec.size(); it++)
		std::cout << " " << _vec[it];
	std::cout << std::endl;
	unsigned long long	timer = getTime();
	fordJohnson(_vec);
	timer = getTime() - timer;
	std::cout << "After:";
	for(size_t it = 0; it != _vec.size(); it++)
		std::cout << " " << _vec[it];
	std::cout << std::endl;
	std::cout << "Time to sort a vector container with Ford-Johnson algorithm : " << timer << "us." << std::endl;
	timer = getTime();
	fordJohnson(_deq);
	std::cout << "Time to sort a deque container with Ford-Johnson algorithm : " << getTime() - timer << "us." << std::endl;
}