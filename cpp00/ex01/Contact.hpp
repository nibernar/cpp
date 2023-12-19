/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:13:06 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/19 13:14:27 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT
#define CONTACT

#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
public:
    std::string getFirstName(void);
    std::string getLasttName(void);
    std::string getNickName(void);
    std::string getPhoneNumber(void);
    std::string getDarkestSecret(void);
    int         newContact(void);
    void        printContact(int i) const;
    void        deleteContact(void);
    Contact();
    ~Contact();
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;
};
#endif