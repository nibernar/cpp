/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:31:18 by nicolasbern       #+#    #+#             */
/*   Updated: 2024/02/23 23:19:51 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    
    iterator begin( void ) {
        return this->c.begin();
    };

    iterator end( void ) {
        return this->c.end();
    };
    
    MutantStack & operator=( MutantStack & rhs) {
        if (this != &rhs)
        {
            std::stack<T>();
            this->c = rhs.c;
        }
        return *this;
    };

    MutantStack( MutantStack & src ) {
        *this = src;
    };

    MutantStack() {};
    ~MutantStack() {};
};

#endif