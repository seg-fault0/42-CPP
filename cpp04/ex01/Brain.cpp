/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:07:36 by wimam             #+#    #+#             */
/*   Updated: 2025/12/27 12:47:06 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy Constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for(int i = 0; i < MAX_IDEAS; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= MAX_IDEAS)
	{
		std::cerr << "ERR setIdea : 0 <= i < " << MAX_IDEAS << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}

std::string	Brain::getIdea(int index)
{
	if (index < 0 || index >= MAX_IDEAS)
	{
		std::cerr << "ERR getIdea : 0 <= i < " << MAX_IDEAS << std::endl;
		return (std::string("no idea found"));
	}
	return (this->ideas[index]);
}