/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:52:20 by nicolasbern       #+#    #+#             */
/*   Updated: 2024/02/26 21:54:09 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int argc, char **argv ) {
    if (argc != 2)
    {
        std::cerr << "ERROR: bad input !" << std::endl;
        return 1;
    }
    std::ifstream inputFile (argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "ERROR: " << argv[1] << " can't open !" << std::endl;
        return 1; 
    }

    try
    {
        BitcoinExchange btc;
        std::string line, value, date;
        while(std::getline(inputFile, line))
        {
            line = BitcoinExchange::trim(line);
            if (line == "date | value")
                continue;
            if (!BitcoinExchange::checkInput(line, '|', date, value))
                continue;
            btc.convert(value, date);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    inputFile.close();
    return 0;
}