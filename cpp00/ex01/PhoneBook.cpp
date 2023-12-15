/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:39:14 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/15 16:09:10 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _lastContactIndex(-1)
{
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::getIndex()
{
	return this->_index;
}


int	PhoneBook::addContact()
{
	if (this->_index > 7)
	{
		this->_lastContactIndex = (this->_lastContactIndex + 1) % 8;
		this->_infoContact[this->_lastContactIndex].deleteContact();
		this->_infoContact[this->_lastContactIndex].newContact();
		return (0);
	}
	if (this->_infoContact[_index++].newContact())
		return (1);
	return (0);	
}

void	print_column(void)
{
	std::cout << std::right << std::setw(10) << "INDEX";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "FIRST NAME";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "LAST NAME";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "NICK NAME" << std::endl;

}

int	PhoneBook::displayContact()
{
	int	i = 0;
	std::string	findIndex;
	int	id = 0;

	print_column();
	while (i < this->_index)
	{
		if (this->_infoContact[i].printContact(i))
			return (1);
		i++;
	}
	std::cout << "ENTER AN INDEX !" << std::endl;
	findIndex.clear();
	std::getline(std::cin, findIndex);
	std::istringstream	sIndex(findIndex);
	sIndex >> id;
	if (isdigit(findIndex[0]) && id <= 8)
	{
		if (this->_infoContact[id].getFirstName().empty())
			return (std::cout << "Index not found!" << std::endl, 0);
		else
			this->_infoContact[id].printContact(id);
	}
	else
		return (std::cout << "Bad index" << std::endl, 0);
	return (0);
}