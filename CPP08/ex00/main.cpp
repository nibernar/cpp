/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:19:13 by nicolasbern       #+#    #+#             */
/*   Updated: 2024/02/23 19:28:37 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {

    std::vector<int> tab;
    tab.push_back(10);
    tab.push_back(-10);
    tab.push_back(32);
    tab.push_back(140);
    tab.push_back(65);
    std::vector<int>::iterator it = easyfind(tab, 5);
    std::cout << *it << std::endl;
    it = easyfind(tab, 10);
    std::cout << *it << std::endl;
    return 0;
}