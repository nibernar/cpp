/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:39:23 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/15 16:04:39 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include <sstream>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int getIndex();
		int	addContact();
		int	displayContact();
	private:
		Contact	_infoContact[8];
		int	_index;
		int	_lastContactIndex;
};

#endif