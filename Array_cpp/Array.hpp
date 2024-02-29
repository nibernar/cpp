/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:28:01 by nicolasbern       #+#    #+#             */
/*   Updated: 2024/02/16 13:47:46 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>
class Array
{
public:
    unsigned int size( void ) const {
        return this->_size;
    };

    T & getArray( unsigned int index ) const {
        return (this->_array[index]);
    };
    
    class outOffLine : public std::exception {
        const char * what(void) const throw() {
            return ("out of line");
        };
    }; 
    
    Array & operator=( Array const &rhs ) {
        if (this != &rhs)
        {
            this->_size = rhs.size();
            delete this->_array;
            this->_array = new T[rhs.size()];
            for (unsigned int i = 0; i < this->_size; i++)
                this->_array[i] = rhs._array[i];
        }
        return *this;
    };
    
    T & operator[]( unsigned int index ) {
        if (index > this->_size)
            throw Array::outOffLine();
        return this->_array[index];
    };
    
    Array( Array const &src ) : _size(src.size()) {
        this->_array = new T[src.size()];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_array[i] = src._array[i];
    };
    Array( unsigned int n ) : _size(n), _array(new T[n]) {};
    Array() : _size(0), _array(new T[0]) {};
    ~Array() {
        delete this->_array;
    };
private:
    unsigned int _size;
    T * _array;
};
template<typename T>
std::ostream & operator<<( std::ostream & out, const Array<T> &src ) {
    for (unsigned int i = 0; i < src.size(); i++)
        out << src.getArray(i) << " ";
    return out;
}
#endif

