/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:13:06 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/13 11:32:34 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT

#include <string>
#include <iostream>

class	Contact
{
	public:
		Contact();
		~Contact();
		std::string	GetFirstName();
		std::string	GetLastName();
		std::string	GetNickName();
		std::string	GetPhoneNumber();
		std::string	GetDarkestSecret();
		int	NewContact();
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;
};

#endif