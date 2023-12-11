/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:39:33 by nibernar          #+#    #+#             */
/*   Updated: 2023/12/09 13:28:46 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		for(int i = 1; i < argc; i++)
			for(int j = 0; argv[i][j]; j++)
			{
				char c = std::toupper(argv[i][j]);
				std::cout << c;
			}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std :: cout << std::endl;
	return (0);
}