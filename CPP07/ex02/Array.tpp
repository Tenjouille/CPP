/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:19:11 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/09 15:50:01 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
	std::cout << "Default constructor called for Array" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) 
{
	std::cout << "Parametric constructor called for Array" << std::endl;
}

template<typename T>
Array<T>::Array(Array const & src) : _array(new T[src._size]), _size(src._size)
{
	std::cout << "Copy constructor called for Array" << std::endl;
	for (unsigned int i = 0; i < src._size; i++)
		this->_array[i] = src._array[i];
}

template<typename T>
Array<T>&	Array<T>::operator=(Array<T> const & hrs)
{
	if (this->_array)
		delete [] this->_array;
	this->_size = hrs._size;
	this->_array = new T[this->_size];
	for (int i = 0; i < hrs._size; i++)
		this->array[i] = hrs.array[i];
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called for Array" << std::endl;
	delete [] this->_array;
}

template<typename T>
T&	Array<T>::operator[](unsigned int idx) const
{
	if (idx >= this->_size)
		throw OutOfBoundException();
	return (this->_array[idx]);
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}

template<typename T>
const char*	Array<T>::OutOfBoundException::what() const throw()
{
	return ("Out of bounds index");
}
