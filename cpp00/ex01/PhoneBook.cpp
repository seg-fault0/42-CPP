/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:50:44 by wimam             #+#    #+#             */
/*   Updated: 2025/11/18 18:12:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*************************************************************/
/***********************   CONSTRUCTOR   *********************/
/*************************************************************/

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_max = 0;
}

/*************************************************************/
/*************************     ADD    ************************/
/*************************************************************/

void PhoneBook::add(void)
{
	Contact		tmpContact;
	std::string	input;

	while (true)
	{
		input = getInput("enter first name : ");
		if (std::cin.eof())
			return ;
		if (tmpContact.setFirstName(input) == true)
			break;
	}
	while (true)
	{
		input = getInput("enter last name : ");
		if (std::cin.eof())
			return ;
		if (tmpContact.setLastName(input) == true)
			break;
	}
	while (true)
	{
		input = getInput("enter nick name : ");
		if (std::cin.eof())
			return ;
		if (tmpContact.setNickName(input) == true)
			break;
	}
	while (true)
	{
		input = getInput("enter phone number : ");
		if (std::cin.eof())
			return ;
		if (tmpContact.setPhoneNbr(input) == true)
			break;
	}
	while (true)
	{
		input = getInput("enter darkest secret : ");
		if (std::cin.eof())
			return ;
		if (tmpContact.setSecret(input) == true)
			break;
	}
	
	this->_contacts[this->_index].setFirstName(tmpContact.getFirstName());
	this->_contacts[this->_index].setLastName(tmpContact.getLastName());
	this->_contacts[this->_index].setNickName(tmpContact.getNickName());
	this->_contacts[this->_index].setPhoneNbr(tmpContact.getPhoneNbr());
	this->_contacts[this->_index].setSecret(tmpContact.getSecret());
	
	this->_index++;
	if (this->_index == MAX_CONTACT)
		this->_index = 0;
	if (this->_max < MAX_CONTACT)
		this->_max++;
}

/*************************************************************/
/*************************   SEARCH   ************************/
/*************************************************************/

void draw_col(std::string str)
{
	int j;
	for(j = 0; j < 9; j++)
	{
		if(j < (int) str.size())
			std::cout << str[j];
		else
			std::cout << " ";
	}
	if(j < (int) str.size())
		std::cout << ".|";
	else
		std::cout << " |";
}

int	ft_atoi(std::string str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}


void PhoneBook::search(void)
{
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|   Index  | frstName | lastName | nickName |" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	
	for(int i = 0; i < this->_max; i++)
	{
		std::cout << "|     " << i << "    |";
		draw_col(this->_contacts[i].getFirstName());
		draw_col(this->_contacts[i].getLastName());
		draw_col(this->_contacts[i].getNickName());
		std::cout << "\n ------------------------------------------- " << std::endl;
	}
	
	std::string input;
	input = getInput("What Contact do you want more infos about : ");
	if (input.empty())
		return ;
	for (int i = 0; input.c_str()[i]; i++)
	{
		if (!std::isdigit(input.c_str()[i]))
		{
			std::cerr << "ERROR : only nbr are allowed" << std::endl;
			return ;
		}
	}

	int index = ft_atoi(input.c_str());
	if (index < 0 || index >= this->_max)
	{
		std::cout << "Err : no such contact" << std::endl;
		return ;
	}
	std::cout << "First Name is : " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name is : " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nick Name is : " << this->_contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number is : " << this->_contacts[index].getPhoneNbr() << std::endl;
	std::cout << "Darkest Secret is : " << this->_contacts[index].getSecret() << std::endl;
}
