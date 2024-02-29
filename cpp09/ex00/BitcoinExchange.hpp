/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:52:22 by nicolasbern       #+#    #+#             */
/*   Updated: 2024/02/26 21:50:27 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTCEX_HPP
#define BTCEX_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

class BitcoinExchange
{
public:
    void convert( std::string const & value, std::string const & date );
    static std::string trim( std::string const & str );
    static bool bissextile(int year);
    static bool checkDate( std::string const & date );
    static bool checkValue( std::string const & value );
    static bool checkInput( std::string const & line, char const & sep, std::string &date, std::string &value );
    BitcoinExchange & operator=( BitcoinExchange const & rhs );
    BitcoinExchange( BitcoinExchange const & src );
    BitcoinExchange();
    ~BitcoinExchange() {};
private:
    std::map<std::string, float> _tab;
};

#endif