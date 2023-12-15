/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:45 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/15 16:08:38 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string	Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string	Contact::getNickName(void)
{
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}

void	Contact::deleteContact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

int	Contact::newContact()
{
	while (this->_firstName.empty())
	{
		std::cout << "First Name: ";
		std::getline(std::cin, this->_firstName);
		if(std::cin.eof())
			return (std::cout << std::endl, 1);
	}
	while (this->_lastName.empty())
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, this->_lastName);
		if(std::cin.eof())
			return (std::cout << std::endl, 1);
	}
	while (this->_nickName.empty())
	{
		std::cout << "Nick Name: ";
		std::getline(std::cin, this->_nickName);
		if(std::cin.eof())
			return (std::cout << std::endl, 1);
	}
	while (this->_phoneNumber.empty())
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, this->_phoneNumber);
		if(std::cin.eof())
			return (std::cout << std::endl, 1);
	}
	while (this->_darkestSecret.empty())
	{
		std::cout << "DarkestSecret: ";
		std::getline(std::cin, this->_darkestSecret);
		if(std::cin.eof())
			return (std::cout << std::endl, 1);
	}
	return (0);
}

int	Contact::printContact(int i)
{
	std::cout << std::right << std::setw(10) << i;
	std::cout << "|";
	std::cout << std::right << std::setw(10) << (this->_firstName.length() > 10 ? this->_firstName.substr(0, 9) + "." : this->_firstName);
	std::cout << "|";
	std::cout << std::right << std::setw(10) << (this->_lastName.length() > 10 ? this->_lastName.substr(0, 9) + "." : this->_lastName);
	std::cout << "|";
	std::cout << std::right << std::setw(10) << (this->_nickName.length() > 10 ? this->_nickName.substr(0, 9) + "." : this->_nickName) << std::endl;
	return (0);
}

Contact::Contact()
{
}

Contact::~Contact()
{
}