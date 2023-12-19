/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:39:23 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/19 13:16:17 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

#define CONTACT_LOG 8
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();
    int addContact(void);
    int displayContact(void);
private:
   Contact  _infoContact[CONTACT_LOG];
   int      _index;
   int      _lastContactIndex;
};

#endif