/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:35:18 by nicolasbern       #+#    #+#             */
/*   Updated: 2024/02/16 13:02:15 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    buzzfizz();
    try
    {
        Array<int> tab(3);
        Array<char> tab2(3);
        Array<int> tab3 = tab;
        tab2[0] = 'a';
        tab2[1] = 'g';
        tab2[2] = 'a';
        Array<char> tableau(tab2);
        std::cout << tab2 << std::endl;
        std::cout << tableau << std::endl;
        tab[0] = 4;
        tab[1] = 6;
        tab[2] = 2;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}