/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:33:51 by nicolasbern       #+#    #+#             */
/*   Updated: 2024/02/23 16:51:16 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int span::shortestSpan( void ) {
	std::vector<int> tmp = this->_tab;
	std::sort(tmp.begin(), tmp.end());
	unsigned int nbr = abs(tmp[0] - tmp[1]);
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		if (nbr > static_cast<unsigned int >(abs(tmp[i] - tmp[i + 1])))
			nbr = abs(tmp[i] - tmp[i + 1]);
	}
    return nbr;
}

int span::longestSpan( void ) {
    return (*std::max_element(this->_tab.begin(), this->_tab.end()) - *std::min_element(this->_tab.begin(), this->_tab.end()));
}

void span::addNumber( unsigned int n ) {
    if (this->_tab.size() >= this->_n)
        throw std::out_of_range("tab is full");
    this->_tab.push_back(n);
}

span & span::operator=( span const &rhs ) {
	if (this != &rhs)
	{
		this->_n = rhs._n;
		this->_tab = rhs._tab;
	}
	return *this;
};

span::span( span const &src ) {
	*this = src;
};

span::span( unsigned int n ) : _n(n),  _tab(0) {
};

span::span() : _n(0), _tab(0) {
};

span::~span() {
};