/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:11:42 by wimam             #+#    #+#             */
/*   Updated: 2025/11/19 15:58:40 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//HEADERS
#include "Contact.hpp"
#include <iostream>

//MACROS
#define MAX_CONTACT 8

//CLASS
class PhoneBook
{
	private:
		Contact	_contacts[MAX_CONTACT];
		int		_index;
		int		_max;
	public:
		PhoneBook(void);
		void	add(void);
		void	search(void);
};

std::string	getInput(std::string prompt);