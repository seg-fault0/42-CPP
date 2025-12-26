/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:55:30 by wimam             #+#    #+#             */
/*   Updated: 2025/12/04 13:56:48 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *ptr = &string;
	std::string &ref = string;

	std::cout << "The memory address of the string variable: "<< &string << std::endl;
	std::cout << "The memory address held by stringPTR: " << ptr << std::endl;
	std::cout << "The memory address held by stringREF: " << &ref << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "The value of the string variable: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: "<< *ptr << std::endl;
	std::cout << "The value pointed to by stringREF: " << ref << std::endl;
	return (0);
}