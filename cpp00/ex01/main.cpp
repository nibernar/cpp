/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:16:42 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/14 22:47:13 by nicolasbern      ###   ########.fr       */
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
		std:: getline(std::cin, str);
		if (str == "ADD")
		{
			if (PhoneBook.AddContact())
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