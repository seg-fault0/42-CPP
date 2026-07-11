/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:51:37 by wimam             #+#    #+#             */
/*   Updated: 2025/12/27 13:24:40 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::string catIdea = "cat idea";
	std::string dogIdea = "dog idea";
	int	animal_nbr = 10;

	Animal *animals[animal_nbr];

	//create
	for (int i = 0; i < animal_nbr; i++)
	{
		if (i < (animal_nbr / 2))
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	
	//fill
	for(int i = 0; i < animal_nbr; i++)
	{
		Cat *cat;
		Dog *dog;
		if (i < (animal_nbr / 2))
		{
			cat = (Cat *) (animals[i]);
			for(int y = 0; y < MAX_IDEAS; y++)
				cat->setIdea(y, catIdea);
		}
		else
		{
			dog = (Dog *) (animals[i]);
			for(int y = 0; y < MAX_IDEAS; y++)
				dog->setIdea(y, dogIdea);
		}
	}
	
	//print
	for(int i = 0; i < animal_nbr; i++)
	{
		Cat *cat;
		Dog *dog;
		if (i < (animal_nbr / 2))
		{
			cat = (Cat *) (animals[i]);
			for(int y = 0; y < MAX_IDEAS; y++)
			{
				std::cout << "animal : " << cat->getType()	\
				<< " | animal index = " << i				\
				<< " | idea index  = " << y					\
				<< " | idea content = " << cat->getIdea(y)	\
				<< std::endl;
			}
		}
		else
		{
			dog = (Dog *) (animals[i]);
			for(int y = 0; y < MAX_IDEAS; y++)
			{
				std::cout << "animal : " << dog->getType()	\
				<< " | animal index = " << i				\
				<< " | idea index  = " << y					\
				<< " | idea content = " << dog->getIdea(y)	\
				<< std::endl;
			}
		}
	}

	//delete
	for (int i = 0; i < animal_nbr; i++)
		delete animals[i];

	return 0;
}