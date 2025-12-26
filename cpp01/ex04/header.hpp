/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:12:17 by wimam             #+#    #+#             */
/*   Updated: 2025/12/09 12:30:54 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>

#define FILENAME 0
#define S1 1
#define S2 2

#define MAX_FILE_SIZE (1 * 1024 * 1024)

#define ERR_USAGE 0
#define ERR_OPEN_I 1
#define ERR_OPEN_O 2
#define ERR_BIG_FILE 3

class Prog
{
	private:
		std::string		filename;
		std::string		s1;
		std::string 	s2;
		std::ifstream	inf;
		std::ofstream	ouf;
	public:
		~Prog();
		bool		init(int ac, char **av);
		void		err_msg(int msg);
		void		run();
};