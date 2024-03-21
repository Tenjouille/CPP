/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:46:42 by tbourdea          #+#    #+#             */
/*   Updated: 2024/02/06 13:44:14 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	ft_print_data(t_Data* data)
{
	if (!data)
		return ;
	std::cout << "\tusername : " << data->username << std::endl << "\tlocation : " << data->location << std::endl << "\tage : " << data->age << std::endl << "\tstudent ? : ";
	if (data->student == true)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
	std::cout << std::endl;
}

void	ft_init(t_Data* data)
{
	if (!data)
		return ;
	data->age = 23;
	data->student = true;
	data->location = "France";
	data->username = "Tenj";
}

void	ft_reinit(t_Data* data)
{
	if (!data)
		return ;
	data->age = 45;
	data->student = false;
	data->location = "Hawai";
	data->username = "Tenjouille";
}

int	main()
{
	// t_Data*		data = 0;
	t_Data*		data = new t_Data;
	uintptr_t	ptr;
	ft_init(data);
	ptr = Serializer::serialize(data);
	std::cout << "Data* =" << std::endl;
	ft_print_data(data);
	std::cout << "uintptr_t =" << std::endl;
	ft_print_data(Serializer::deserialize(ptr));
	std::cout << ptr << std::endl;
	std::cout << data << " = " << Serializer::deserialize(ptr) << std::endl << "__________________________________           __________________________________" << std::endl << "__________________________________CHANGE DATA__________________________________" << std::endl << std::endl;
	ft_reinit(data);
	std::cout << "Data* =" << std::endl;
	ft_print_data(data);
	std::cout << "uintptr_t =" << std::endl;
	ft_print_data(Serializer::deserialize(ptr));
	std::cout << "serialized : " << ptr << " = " << Serializer::serialize(data) << std::endl;
	std::cout << "unserialized : " << data << " = " << Serializer::deserialize(ptr) <<  std::endl << std::endl;
	delete data;
	
	return (0);
}
