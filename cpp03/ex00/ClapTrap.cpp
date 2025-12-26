/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:56:51 by wimam             #+#    #+#             */
/*   Updated: 2025/12/24 10:50:17 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
};

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
	name = "Unknown";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(const std::string name)
{
	std::cout << "ClapTrap name Constructor called" << std::endl;
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}


ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target \
		<< ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is not able to attack " << target \
		<< ", because he has no energy points left." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " is not able to attack " << target \
		<< ", because he has not enough hit points." << std::endl;	
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > amount)
		this->hit_points -= amount;
	else if (this->hit_points > 0)
		this->hit_points = 0;
	else
	{
		std::cout << "ClapTrap " << this->name << " is already dead, stop beating it." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount \
	<< " hit points, he now has " << this->hit_points << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0 && this->hit_points > 0 && this->hit_points + amount <= 10)
	{
		this->hit_points += amount;
		std::cout << "ClapTrap " << this->name << " repaired itself and gained " << amount << " of hit points, he now has " << this->hit_points << "hit points." << std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name \
		<< " is not able to repair itself, because he doesn't have enough energy points." << std::endl;
	}
	else if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name \
		<< " is not able to repair itself, because he doesn't have enough hit points." << std::endl;	
	}
	else
	{
		std::cout << "ClapTrap " << this->name \
		<< " can't be repaired to have more than 10 hit points." << std::endl;
	}
}