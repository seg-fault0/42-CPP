/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:50:40 by wimam             #+#    #+#             */
/*   Updated: 2025/11/18 17:50:40 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	getInput(std::string prompt)
{
	std::string	line;

	std::cout << prompt;
	std::getline(std::cin, line);
	return (line);
}

int main()
{
	PhoneBook	contact;
	std::string	input;

	while(true)
	{
		input = getInput("Enter command : ");
		if (input == "EXIT" || std::cin.eof())
			break ;
		else if (input == "ADD")
			contact.add();
		else if (input == "SEARCH")
			contact.search();
	}
}
