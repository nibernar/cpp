/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:39:14 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/19 13:15:08 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void    printTab(void);

int PhoneBook::addContact(void) {
    std::cout << BLUE << "      ENTRER LES COORDONEES:" << std::endl;
    if (this->_index > CONTACT_LOG - 1)
    {
        this->_lastContactIndex = (this->_lastContactIndex + 1) % CONTACT_LOG;
        this->_infoContact[this->_lastContactIndex].deleteContact();
        this->_infoContact[this->_lastContactIndex].newContact();
        return (1);
    }
    if (this->_infoContact[_index++].newContact())
        return (1);
    return (0);
}


int PhoneBook::displayContact(void) {
    std::string input;
    int         index;

    printTab();
    index = 0;
    for (int i = -1; ++i < this->_index;)
        this->_infoContact[i].printContact(i);
    std::cout << BLUE << "     ENTREZ UN INDEX PAGEJAUNE :";
    std::getline(std::cin, input);
    std::istringstream	sIndex(input);
	sIndex >> index;
    if (isdigit(input[0]) && !input[1] && index <= 8)
    {
        if (this->_infoContact[index].getFirstName().empty())
            return (std::cout << RED << "     CONTACT NOT FOUND 🖕" << std::endl, 0);
        else
            this->_infoContact[index].printContact(index);
    }
    else
       return (std::cout << RED << "\n     WRONG INDEX ⛔️" << std::endl, 0);
    return (0);
}

static void    printTab(void) {
    std::cout << GREEN << std::right << std::setw(10) << "INDEX" << "|";
    std::cout << GREEN << std::right << std::setw(10) << "FRIST NAME" << "|";
    std::cout << GREEN << std::right << std::setw(10) << "LAST NAME" << "|";
    std::cout << GREEN << std::right << std::setw(10) << "NICK NAME" << std::endl;
}

PhoneBook::PhoneBook() : _index(0), _lastContactIndex(-1)
{
}

PhoneBook::~PhoneBook()
{
}