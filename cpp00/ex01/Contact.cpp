/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:45 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/19 13:14:02 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName(void) {
    return (this->_firstName);
}

std::string Contact::getLasttName(void) {
    return (this->_lastName);
}

std::string Contact::getNickName(void) {
    return (this->_nickName);
}

std::string Contact::getPhoneNumber(void) {
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) {
    return (this->_darkestSecret);
}

int Contact::newContact(void) {
    while(this->_firstName.empty())
    {
        std::cout << "  FIRST NAME :";
        std::getline(std::cin, this->_firstName);
        if (std::cin.eof())
            return (std::cout << std::endl, 1);
    }

    while(this->_lastName.empty())
    {
        std::cout << "  LAST NAME :";
        std::getline(std::cin, this->_lastName);
        if (std::cin.eof())
            return (std::cout << std::endl, 1);
    }
    while(this->_nickName.empty())
    {
        std::cout << "  NICK NAME :";
        std::getline(std::cin, this->_nickName);
        if (std::cin.eof())
            return (std::cout << std::endl, 1);
    }
    while(this->_phoneNumber.empty())
    {
        std::cout << "  PHONE NUMBER :";
        std::getline(std::cin, this->_phoneNumber);
        if (std::cin.eof())
            return (std::cout << std::endl, 1);
    }
    while(this->_darkestSecret.empty())
    {
        std::cout << "  DARKEST SECRET :";
        std::getline(std::cin, this->_darkestSecret);
        if (std::cin.eof())
            return (std::cout << std::endl, 1);
    }
    std::cout << "      COORDONEES ENREGISTE" << std::endl;
    return (0);
}

void	Contact::deleteContact() {
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

void    Contact::printContact(int i) const {
    std::cout << std::right << std::setw(10) << i << "|";
    std::cout << std::right << std::setw(10) <<  (this->_firstName.length() > 10 ? this->_firstName.substr(0, 9) + "." : this->_firstName) << "|";
    std::cout << std::right << std::setw(10) <<  (this->_lastName.length() > 10 ? this->_lastName.substr(0, 9) + "." : this->_lastName) << "|";
    std::cout << std::right << std::setw(10) <<  (this->_nickName.length() > 10 ? this->_nickName.substr(0, 9) + "." : this->_nickName) << std::endl;
}

Contact::Contact()
{
}

Contact::~Contact()
{
}