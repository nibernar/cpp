/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:45 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/13 12:23:27 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::~Contact()
{
	
}

std::string	Contact::GetFirstName()
{
	return this->_FirstName;
}

std::string	Contact::GetLastName()
{
	return	this->_LastName;
}

std::string	Contact::GetNickName()
{
	return	this->_NickName;
}

std::string	Contact::GetPhoneNumber()
{
	return	this->_PhoneNumber;
}

std::string	Contact::GetDarkestSecret()
{
	return this->_DarkestSecret;
}

int	Contact::NewContact()
{
	while(this->_FirstName.empty())
	{
		std::cout << "First Name: ";
		std::getline(std::cin, this->_FirstName);
		if (std::cin.eof())
			return(std::cout << std::endl, 1);
	}
	while(this->_LastName.empty())
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, this->_LastName);
		if (std::cin.eof())
			return (std::cout << std::endl, 1);
	}
	while(this->_NickName.empty())
	{
		std::cout << "Nick Name: ";
		std::getline(std::cin, this->_NickName);
		if(std::cin.eof())
			return(std::cout << std::endl, 1);
	}
	
	while (this->_PhoneNumber.empty())
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, this->_PhoneNumber);
		if (std::cin.eof())
			return (std::cout << std::endl, 1);
	}
	
	while (this->_DarkestSecret.empty())
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, this->_DarkestSecret);
		if (std::cin.eof())
			return (std::cout << std::endl, 1);
	}
	return (0);
}