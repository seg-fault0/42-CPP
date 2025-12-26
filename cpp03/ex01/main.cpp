/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:02:03 by wimam             #+#    #+#             */
/*   Updated: 2025/12/24 10:58:59 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap a("Clappy");
	ScavTrap b("Scavy");

	a.attack("Scavy");
	b.takeDamage(0);

	b.attack("Clappy");
	a.takeDamage(20);

	b.beRepaired(10);
	b.guardGate();
	b.guardGate();

	return 0;
}