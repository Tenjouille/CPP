/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:07:11 by tbourdea          #+#    #+#             */
/*   Updated: 2024/03/03 19:17:29 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <iostream>
# include <sstream>
# include <unistd.h>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <iterator>
# include <fstream>
# include <cmath>
# include <string.h>
# include <map>
# include <set>

class BitcoinExchange
{
private:
    std::map<std::string, float>    _dataBase;
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & src);
    BitcoinExchange& operator=(BitcoinExchange const & hrs);
    ~BitcoinExchange();

    std::string getDate(std::string line);
    float       getValue(std::string line);
    float       closestValue(std::string line);
    void        scan(std::string file);
    void        cmp(std::string line);
};

#endif

