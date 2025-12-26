/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:50:33 by wimam             #+#    #+#             */
/*   Updated: 2025/11/18 17:50:33 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNbr;
		std::string	secret;
	public:
		//seters
		bool	setFirstName(std::string firstName);
		bool	setLastName(std::string lastName);
		bool	setNickName(std::string nickName);
		bool	setPhoneNbr(std::string phoneNbr);
		bool	setSecret(std::string secret);
		//geters
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getPhoneNbr(void);
		std::string getSecret(void);
};
