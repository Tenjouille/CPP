/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:46:48 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/09 16:05:18 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// int	main(int ac, char** av)
// {
// 	Array<int>			buff(11);
// 	Array<std::string>	str_buff(ac - 1);;
// 	Array<char>			null_buff;	

// 	if (!null_buff.size())
// 		std::cout << "null_buff is an empty array" << std::endl;
// 	for (unsigned int i = 0; i < buff.size(); i++)
// 	{
// 		buff[i] = i;
// 		std::cout << buff[i] << std::endl;
// 	}
// 	std::cout << std::endl;
// 	for(unsigned int i = 0; i < str_buff.size(); i++)
// 	{
// 		str_buff[i] = av[i + 1];
// 		std::cout << str_buff[i] << std::endl;
// 	}
// 	try
// 	{
// 		buff[0] = 10;
// 		buff[12] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	for (unsigned int i = 0; i < buff.size(); i++)
// 		std::cout << buff[i] << std::endl;
	
// 	return (0);
// }


