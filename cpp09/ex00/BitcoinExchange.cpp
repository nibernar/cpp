/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:52:25 by nicolasbern       #+#    #+#             */
/*   Updated: 2024/02/26 22:24:29 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string BitcoinExchange::trim( std::string const & str ) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;
    size_t seconde = str.find_last_not_of(' ');
    return (str.substr(first, seconde - first + 1));
}

bool BitcoinExchange::bissextile(int year) {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

void BitcoinExchange::convert( std::string const & value, std::string const & date ) {
    float btcValue = 0;

	if (date < this->_tab.begin()->first) 
    {
		std::cerr << "Btc did not exist in " << date << std::endl;
		return ;
	}
	for (std::map<std::string, float>::iterator it = this->_tab.begin(); it != this->_tab.end(); it++) 
    {
    	if (it->first >= date) 
        {
			if (it->first > date) 
				it--;
			btcValue = atof(value.c_str()) * it->second;
			break ;
		}
	}
	std::cout << date << "=>" << value << " = " << btcValue  << std::endl;
}

bool BitcoinExchange::checkDate( std::string const & date ) {
    if (date.length() != 11)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                return false;
            }
        }
        else
            if (!std::isdigit(date[i]))
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                return false;        
            }
    }
    int year, month, day;
    year = atoi(date.substr(0, 4).c_str());
    month = atoi(date.substr(5, 2).c_str());
    day = atoi(date.substr(8, 2).c_str());
    int formatDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (bissextile(year))
        formatDay[1] = 29;
    if (year < 2008)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;        
    }
    if (month < 1 || month > 12)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;        
    }
    if (day < 1 || day > formatDay[month - 1])
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;       
    }
    return true;
}

bool BitcoinExchange::checkValue( std::string const & value ) {
    if (value.length() == 0)
    {
        std::cerr << "Error: bad input value not found => " <<  value << std::endl;
        return false;
    }
    if (value[0] != ' ')
    {
        std::cerr << "Error: bad input need space => " <<  value << std::endl;
        return false;
    }
    if (!isdigit(value[1]))
    {
        if (value[1] == '-')
            std::cerr << "Error: not a positive number." << std::endl;
        else
            std::cerr << "Error: bad input need number => " <<  value << std::endl;
        return false;
    }
    size_t pointPose = value.find('.');
    if (value.find('.') != std::string::npos)
    {
        if (value.find('.', pointPose + 1) != std::string::npos)
        {
            std::cerr << "Error: format float needed => " <<  value << std::endl;
            return false;
        }
    }
    for (size_t i = 1; i < value.length(); i++)
    {
        if (value[i] == '.' && !isdigit(value[i + 1]))
        {
            std::cerr << "Error: format float needed => " <<  value << std::endl;
            return false;
        }
        if (value[i] != '.' && !isdigit(value[i]))
        {
            std::cerr << "Error: format float needed => " <<  value << std::endl;
            return false; 
        }
    }
	float amount = strtod(value.c_str(), NULL);
	if (amount < 0.0f || amount > 1000.0f) 
    {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
    return true;
}

bool BitcoinExchange::checkInput( std::string const & line , char const & sep , std::string &date, std::string &value ) {
    if (line.find(sep) == std::string::npos)
    {
        std::cerr << "Error: bat input => " << line.substr(0, line.find(sep)) << std::endl;
        return false;
    }
    if (sep == ',')
    {
        date = line.substr(0, line.find(sep)) + ' ';
        value = ' ' + line.substr(line.find(sep) + 1);
    }
    else
    {
        date = line.substr(0, line.find(sep));
        value = line.substr(line.find(sep) + 1);
        if (!checkValue(value))
            return false;
    }
    if (!checkDate(date))
        return false;
    return true;
}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & rhs ) {
    if (this != &rhs)
        this->_tab = rhs._tab;
    return *this;
};

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) {
    *this = src;
};

BitcoinExchange::BitcoinExchange () {
    std::ifstream data ("data.csv");
    std::string input, date, value;
    if (!data.is_open())
        throw std::out_of_range("Error: openFile fail !");
    while (std::getline(data, input))
    {
        input = trim(input);
        if (input == "date,exchange_rate")
            continue;
        if (checkInput(input, ',', date, value))
            this->_tab[date] = strtod(value.c_str(), NULL);
    }
    data.close();
};