/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:16:42 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/11 15:50:06 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void	AddContact(PhoneBook *PhoneBook)
{
	std::string	InfoContact[5];
}

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string str;

	while (1)
	{
		std:: getline(std::cin, str);
		if (str == "ADD")
			AddContact(&PhoneBook);
		else if (str == "SEARCH")
			std::cout << "SEARCH" << std::endl;
		else if (str == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			return (0);
		}
		else
			std::cout << "BAD ARG" << std::endl;
	}
}