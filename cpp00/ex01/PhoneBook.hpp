/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:39:23 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/14 22:59:40 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int	AddContact();
		int	displayContact();
	private:
		Contact	InfoContact[5];
		int	index;
};

#endif