/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:07:31 by nicolasbern       #+#    #+#             */
/*   Updated: 2024/02/23 16:59:40 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class span
{
public:
	
	template <typename it>
	void addNumbers(it begin, it end) {
		if (this->_tab.size() >= this->_n)
        	throw std::out_of_range("tab is full");
		this->_tab.insert(this->_tab.end(), begin, end);
	}

	int shortestSpan( void );
	int longestSpan( void );
	void addNumber( unsigned int n );
	span & operator=( span const &rhs );
	span( span const &src );
	span( unsigned int n );
	span();
	~span();
private:
	unsigned int _n;
	std::vector<int> _tab;
};

#endif