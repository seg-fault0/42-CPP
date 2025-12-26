/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:19:28 by wimam             #+#    #+#             */
/*   Updated: 2025/12/04 13:31:32 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int n = 5;
	Zombie *zombies = zombieHorde(n, "Foo");
	
	for(int i = 0; i < n; i++)
		zombies[i].announce();
	
	delete [] zombies;
	return(0);
}