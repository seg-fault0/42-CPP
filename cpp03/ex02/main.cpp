/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:02:03 by wimam             #+#    #+#             */
/*   Updated: 2025/12/24 11:01:07 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap a("Clap");
	ScavTrap b("Scav");
	FragTrap c("Frag");

	a.attack("Scav");
	b.takeDamage(0);

	b.attack("Frag");
	c.takeDamage(20);

	c.attack("Clap");
	a.takeDamage(30);

	c.highFivesGuys();

	return 0;
}