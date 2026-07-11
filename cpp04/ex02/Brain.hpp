/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:05:09 by wimam             #+#    #+#             */
/*   Updated: 2025/12/27 12:28:18 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define MAX_IDEAS 100

class Brain
{
	protected:
		std::string	ideas[MAX_IDEAS];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
		
		void	setIdea(int index, std::string idea);
		
		std::string	getIdea(int index);
};