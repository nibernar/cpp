/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:39:14 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/14 23:00:18 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0)
{
    
}

PhoneBook::~PhoneBook()
{
    
}

int PhoneBook::AddContact()
{
    if  (this->InfoContact[index].NewContact())
        return (1);
    return (0);
}

void    printColumn(void)
{
    std::cout << std::right << std::setw(10) << "INDEX" << "|";
    std::cout << std::right << "FIRST NAME" << "|";
    std::cout << std::right << "LAST NAME" << "|";
    std::cout << std::right << "NICK NAME" << std::endl;
}

int PhoneBook::displayContact()
{
    printColumn();
    return (0);
}

