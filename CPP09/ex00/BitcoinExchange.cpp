/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:07:11 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/04 10:40:40 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	infile("data.csv");
	std::string		line;
	
	if (!infile.is_open())
		throw "Error : data.csv not found.";
	getline(infile, line);
	if (line != "date,exchange_rate")
		throw "Error : wrong data.csv header.";
	for(int i = 2; i <= 1613; i++)
	{
		getline(infile, line);
		_dataBase.insert(std::pair<std::string, float>(getDate(line), getValue(line)));
	}
	// for(std::map<std::string, float>::iterator it = _dataBase.begin(); it != _dataBase.end(); it++)
	// 	std::cout << "[" << it->first << "," << it->second << "]" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	_dataBase = src._dataBase;
	std::cout << "Copy constructor called for BitcoinExchange" << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	std::cout << "Assignment operator called for BitcoinExchange" << std::endl;
	_dataBase = rhs._dataBase;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	return ;
}

std::string	BitcoinExchange::getDate(std::string line)
{
	return (line.assign(line, 0, 10));
}

float	BitcoinExchange::getValue(std::string line)
{
	return (strtof(line.assign(line, 11, line.size()).c_str(), NULL));
}


void	specialCharCount(std::string str, std::string date, std::string value, std::string file)
{
	std::string	err;

	if (std::count(date.begin(), date.end(), '.') != 0 || std::count(value.begin(), value.end(), '.') > 1)
		throw ("Error : wrong " + file + " format => " + str);
	if (std::count(str.begin(), str.end(), ' ') != 2 || value.at(value.size() - 1) == '.' || value[0] == '.')
		throw ("Error : wrong " + file + " format => " + str);
	if (std::count(str.begin(), str.end(), '|') != 1 || std::count(value.begin(), value.end(), 'f') > 1)
		throw ("Error : wrong " + file + " format => " + str);
	if (std::count(date.begin(), date.end(), '-') != 2 || std::count(value.begin(), value.end(), '-') > 1)
		throw ("Error : wrong " + file + " format => " + str);
	if (std::count(date.begin(), date.end(), '+') != 0 || std::count(value.begin(), value.end(), '+') > 1)
		throw ("Error : wrong " + file + " format => " + str);
	if (std::count(value.begin(), value.end(), '+') == 1 && std::count(value.begin(), value.end(), '-') == 1)
		throw ("Error : wrong " + file + " format => " + str);
	if (std::count(value.begin(), value.end(), 'f') == 1 && value.at(value.size() - 1) != 'f')
		throw ("Error : wrong " + file + " format => " + str);
}

void	defineToday(int today[3])
{
	time_t		rawtime;
	struct tm	*timeinfo;
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);

    today[0] = timeinfo->tm_year + 1900;
    today[1] = timeinfo->tm_mon + 1;
    today[2] = timeinfo->tm_mday;
}

std::string	validDate(std::string year, std::string month, std::string day, int today[3])
{
	int	oddMonth[7] = {1, 3, 5, 7, 8, 10, 12};
	int	evenMonth[4] = {4, 6, 9, 11};

	if (atoi(year.c_str()) < 0 || atoi(year.c_str()) > today[0])
		return ("Error : date is unvalid => ");
	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
		return ("Error : date is unvalid => ");
	if (std::find(oddMonth, oddMonth+7, atoi(month.c_str())) != oddMonth+7) {
		if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31)
			return ("Error : date is unvalid => ");
	}
	else if (std::find(evenMonth, evenMonth+4, atoi(month.c_str())) != evenMonth+4) {
		if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 30)
			return ("Error : day is unvalid => ");
	}
	else if ((!atoi(year.c_str()) % 4 && atoi(year.c_str()) % 100) || !atoi(year.c_str()) % 400) {
		if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 29)
			return ("Error : day is unvalid => ");
	}
	else
		if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 28)
			return ("Error : day is unvalid => ");
	if (atoi(day.c_str()) > today[2] && atoi(month.c_str()) >= today[1] && atoi(year.c_str()) >= today[0])
		return ("Error : date can not be in the future => ");
	return ("");
}

void	checkDate(std::string date, std::string file)
{
	std::string	err;
	std::string	year;
	std::string	month;
	std::string	day;
	int			today[3];

	for (size_t i = 0; i < date.size(); i++)
	{
		if ((date[i] < '0' || date[i] > '9') && date[i] != '-')
			throw ("Error : wrong " + file + " date => " + date);
	}
	defineToday(today);
	year.assign(date, 0, 4);
	month.assign(date, 5, 2);
	day.assign(date, 8, 2);
	if (validDate(year, month, day, today) != "")
		throw validDate(year, month, day, today) + date;
}

void	checkValue(std::string value, std::string file)
{
	std::string	err;
	int			count = 0;

	for (size_t i = 0; i < value.size(); i++)
	{
		if ((value[i] < '0' || value[i] > '9') && value[i] != '-' && value[i] != '.' && value[i] != '+' && value[i] !=  'f')
			throw ("Error : wrong " + file + " value => " + value);
		if (value[i] == '-' || value[i] == '+')
			count++;
	}
	if (count > 1 || (count == 1 && value[0] != '-' && value[0] != '+'))
		throw ("Error : wrong " + file + " value => " + value);
	if (value[0] == '-') {
		throw ("Error : not a positive number => " + value);
	}
	switch (std::count(value.begin(), value.end(), '.'))
	{
	case 0:
		if (strtol(value.c_str(), NULL, 10) > 1000)
			throw ("Error : too large number => " + value);
		break;
	case 1:
		if (strtof(value.c_str(), NULL) > 1000 || value.substr(0, 6) == "1000.0")
			throw ("Error : too large number => " + value);
		break;
	}
}

void	checkLine(std::string str, std::string file)
{
	std::string	err;
	std::string	date;
	std::string	value;

	if (str[11] != '|' || str[4] != '-' || str[7] != '-' || str[10] != ' ' || str[12] != ' ')
		throw ("Error : wrong " + file + " format => " + str);
	date.assign(str, 0, 10);
	value.assign(str, 13, str.size() - 13);
	specialCharCount(str, date, value, file);
	checkDate(date, file);
	checkValue(value, file);
}

float	BitcoinExchange::closestValue(std::string date)
{
	std::map<std::string, float>::iterator	it;

	it = this->_dataBase.upper_bound(date);
	if (it == this->_dataBase.begin())
		throw ("Error : There is no data about Bitcoin value before 2009-01-02 => " + date);
	--it;
	return (it->second);
}

void	BitcoinExchange::cmp(std::string line)
{
	std::string	value;
	float		closest = this->closestValue(getDate(line));

	value.assign(line, 13, line.size() - 13);
	std::cout << getDate(line) << " => " << value << " = ";
	std::cout << closest * strtof(value.c_str(), NULL) << std::endl;
}

void	BitcoinExchange::scan(std::string file)
{
	std::ifstream	infile(file.c_str());
	std::string		line;
	std::string		err;

	if (!infile.is_open())
		throw ("Error : " + file + " not found.");
	getline(infile, line);
	if (line != "date | value")
		throw ("Error : wrong " + file + " header.");
	while (getline(infile, line))
	{
		if (line.size() == 0) {
			std::cout << std::endl;
			continue ;
		}
		try
		{
			
			checkLine(line, file);
			this->cmp(line);
		}
		catch(std::string msg)
		{
			std::cerr << msg << std::endl;
		}
	}
}
