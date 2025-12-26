/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:53:32 by wimam             #+#    #+#             */
/*   Updated: 2025/12/13 18:02:12 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	Point inside(1, 1);
	Point outside(6, 6);
	Point onEdge(0, 2);
	
	std::cout << std::boolalpha;
	std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "On Edge: " << bsp(a, b, c, onEdge) << std::endl;
	std::cout << std::noboolalpha;

	return 0;
}