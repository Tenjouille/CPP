/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:11:28 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/05 11:26:22 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0)
{
	std::cout << "Default constructor called for Span" << std::endl;
}

Span::Span(size_t n) : _size(n)
{
	std::cout << "Parametric constructor called for Span" << std::endl;
}

Span::Span(Span const & src) : _size(src._size)
{
	std::cout << "Copy constructor called for Span" << std::endl;
}

Span&	Span::operator=(Span const & rhs)
{
	std::cout << "Assignment operator called for Span" << std::endl;
	_span = rhs._span;
	_size = rhs._size;
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor called for Span" << std::endl;
}

void	Span::addNumber(int n)
{
	if (this->_span.size() == this->_size)
		throw FullSpanException();
	this->_span.push_back(n);
	std::cout << "1 value added to the span" << std::endl;
}

void	Span::addNumber(std::vector<int> moreValues)
{
	if (this->_span.size() + moreValues.size() > this->_size)
		throw FullSpanException();
	this->_span.insert(this->_span.end(), moreValues.begin(), moreValues.end());
	if (moreValues.size() == 1)
		std::cout << "1 value added to the span" << std::endl;
	else
		std::cout << moreValues.size() << " values added to the span" << std::endl;
}

int		Span::shortestSpan()
{
	if (this->_size <= 1)
		throw NoDiffException();

	int	min = std::abs(this->_span.at(0) - this->_span.at(1));
	unsigned long	i = 0;
	unsigned long	j = 1;

	while (i != this->_span.size() - 1)
	{
		j = i + 1;
		while (j != this->_span.size())
		{
			if (std::abs(this->_span.at(i) - this->_span.at(j)) < min)
				min = std::abs(this->_span.at(i) - this->_span.at(j));
			j++;
		}
		i++;
	}
	return (min);
}

int		Span::longestSpan()
{
	if (this->_size <= 1)
		throw NoDiffException();
	std::sort(this->_span.begin(), this->_span.end());
	return (this->_span.back() - this->_span.front());
}

void	Span::print()
{
	std::cout << "[";
	for (unsigned long i = 0; i < this->_size; i++)
	{
		std::cout << this->_span.at(i);
		if (i != this->_size - 1)
			std::cout << " ";
	}
	std::cout << "]" << std::endl;
}

const char* Span::NoDiffException::what() const throw()
{
	return("\033[31mNot enough numbers in span to determine any distance between them\033[0m");
}

const char* Span::FullSpanException::what() const throw()
{
	return("\033[31mSpan is full, you can't add more numbers\033[0m");
}
