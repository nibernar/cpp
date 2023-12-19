/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:16:42 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/19 13:14:47 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

static void    welcome(void)
{
        std::cout << GREEN << "      WELCOME PAGEJAUNE" << std::endl;
        std::cout << BLUE << "  OPTION 1 => ADD\n";
        std::cout << BLUE << "  OPTION 2 => SEARCH\n";
        std::cout << BLUE << "  OPTION 1 => EXIT" << std::endl;
}

int main(void)
{
    std::string input;
    PhoneBook   pageJaune;

    welcome();
    while(1)
    {
        if (std::cin.eof())
            return (std::cout << std::endl, 1);
        input.clear();
        std::cout << BLUE << "      CHOIX :";
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            if (pageJaune.addContact())
                break ;
        }
        else if (input == "SEARCH")
        {
            if (pageJaune.displayContact())
                break ;
        }
        else if (input == "EXIT")
        {
            std::cout << GREEN << "      A BIENTOT 🤙" << std::endl;
            return (0);
        }
        else
            std::cout << RED << "\n      BAD OPTION 🖕" << std::endl;
    }
    return (0);
}