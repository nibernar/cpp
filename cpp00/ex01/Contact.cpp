/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:45 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/11 15:30:57 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::GetFirstName(void)
{
	return (this->_FirstName);
}

std::string	Contact::GetLastName(void)
{
	return (this->_LastName);
}

std::string	Contact::GetNickName(void)
{
	return (this->_NickName);
}

std::string	Contact::GetPhoneNumber(void)
{
	return (this->_PhoneNumber);
}

std::string	Contact::GetDarkestSecret(void)
{
	return (this->_DarkestSecret);
}

Contact::Contact()
{
}

Contact::~Contact()
{
}