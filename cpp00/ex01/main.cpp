/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:16:42 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/15 16:05:38 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string str;

	while (1)
	{
		if(std::cin.eof())
			return (std::cout << std::endl, 1);
		str.clear();
		std::getline(std::cin, str);
		if (str == "ADD")
		{
			if (PhoneBook.addContact())
				break;
		}
		else if (str == "SEARCH")
		{
			if (PhoneBook.displayContact())
				break;
		}
		else if (str == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			return (0);
		}
		else
			std::cout << "BAD ARG" << std::endl;
	}
}