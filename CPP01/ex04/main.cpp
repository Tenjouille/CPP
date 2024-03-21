/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:32:46 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/15 18:50:27 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int	ft_replace_loop(std::string line, std::string s1, std::string s2)
{
	std::size_t		occur = 0;
	std::ifstream	infile(line.c_str());
	
	if (!infile.is_open())
		return (std::cout << "Wrong path to filename" << std::endl, 1);
	std::ofstream	outfile((line + ".replace").c_str());
	if (!outfile.is_open())
		return (std::cout << "Sorry, we can't create a " << line << ".replace outfile, a file or directory already has this name."<< std::endl, 1);
	std::getline(infile, line, '\0');
	while (1)
	{
		occur = line.find(s1);
		if (occur == std::string::npos)
			break ;
		for(size_t i = 0; i < occur; i++)
		{
			outfile << line[0];
			line.erase(line.begin());
		}
		outfile << s2;
		for(size_t i = 0; i < s1.length(); i++)
			line.erase(line.begin());
	}
	outfile << line;
	infile.close();
	outfile.close();
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Wrong number of arguments" << std::endl, 1);
	if (!av[2][0])
		return (std::cout << "s1 can't be NULL" << std::endl, 1);
	std::string		line = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];

	return (ft_replace_loop(line, s1, s2));
}
