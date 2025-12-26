/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:45:29 by wimam             #+#    #+#             */
/*   Updated: 2025/11/29 15:03:46 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*************************************************************/
/*************************   SETERS   ************************/
/*************************************************************/

bool	Contact::setFirstName(std::string firstName)
{
	if (firstName.empty())
	{
		std::cerr << "ERROR : Input is empty" << std::endl;
		return (false);
	}
	for (int i = 0; firstName.c_str()[i]; i++)
	{
		if (std::isdigit(firstName.c_str()[i]))
		{
			std::cerr << "ERROR : first name contain a number" << std::endl;
			return (false);
		}
	}
	this->firstName = firstName;
	return (true);
}

bool	Contact::setLastName(std::string lastName)
{
	if (lastName.empty())
	{
		std::cerr << "ERROR : Input is empty" << std::endl;
		return (false);
	}
	for (int i = 0; lastName.c_str()[i]; i++)
	{
		if (std::isdigit(lastName.c_str()[i]))
		{
			std::cerr << "ERROR : last name contain a number" << std::endl;
			return (false);
		}
	}
	this->lastName = lastName;
	return (true);
}

bool	Contact::setNickName(std::string nickName)
{
	if (nickName.empty())
	{
		std::cerr << "ERROR : Input is empty" << std::endl;
		return (false);
	}
	this->nickName = nickName;
	return (true);
}

bool	Contact::setPhoneNbr(std::string phoneNbr)
{
	if (phoneNbr.empty())
	{
		std::cerr << "ERROR : Input is empty" << std::endl;
		return (false);
	}
	for (int i = 0; phoneNbr.c_str()[i]; i++)
	{
		if (!std::isdigit(phoneNbr.c_str()[i]))
		{
			std::cerr << "ERROR : phone number has non num chars" << std::endl;
			return (false);
		}
	}
	this->phoneNbr = phoneNbr;
	return (true);
}

bool	Contact::setSecret(std::string secret)
{
	if (secret.empty())
	{
		std::cerr << "ERROR : Input is empty" << std::endl;
		return (false);
	}
	this->secret = secret;
	return (true);
}

/*************************************************************/
/*************************   GETERS   ************************/
/*************************************************************/

std::string	Contact::getFirstName(void)
{
	return (this->firstName);
}
std::string	Contact::getLastName(void)
{
	return(this->lastName);
}
std::string	Contact::getNickName(void)
{
	return (this->nickName);
}
std::string	Contact::getPhoneNbr(void)
{
	return (this->phoneNbr);
}
std::string	Contact::getSecret(void)
{
	return (this->secret);
}
