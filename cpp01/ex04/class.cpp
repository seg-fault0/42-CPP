/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:20:22 by wimam             #+#    #+#             */
/*   Updated: 2025/12/09 12:25:40 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/*************************************************/
/****************     INIT    *******************/
/*************************************************/
bool	Prog::init(int ac, char **av)
{
	if (ac != 4)
		return (err_msg(ERR_USAGE), false);
	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	inf.open(filename.c_str());
	if (!inf.is_open())
		return (err_msg(ERR_OPEN_I), false);

	inf.seekg(0, std::ios::end);
	if (inf.tellg() > MAX_FILE_SIZE)
		return (err_msg(ERR_BIG_FILE), false);
	inf.seekg(0, std::ios::beg);

	ouf.open((filename + ".replace").c_str());
	if (!ouf.is_open())
		return (err_msg(ERR_OPEN_O), false);
	return (true);
}

/*************************************************/
/**************     Destructor    ****************/
/*************************************************/
Prog::~Prog()
{
	if (inf.is_open())
		inf.close();
	if (ouf.is_open())
		ouf.close();
}

/*************************************************/
/****************     LUNCHER    *****************/
/*************************************************/
void	Prog::run()
{
	std::string	line;
	std::string newLine;
	int			pos;

	std::getline(inf, line, '\0');
	newLine = line;
	while (!s1.empty() && line.find(s1) != std::string::npos)
	{
		pos = line.find(s1);
		newLine = (line.substr(0, pos) + s2 + line.substr(pos + s1.length()));
		line = newLine;
	}
	ouf << newLine;
}

/*************************************************/
/***************     Other    *******************/
/*************************************************/
void	Prog::err_msg(int msg)
{
	std::cerr << "ERR : ";
	if (msg == 0)
		std::cerr << "usage : ./Sed_is_for_losers <path/to/file> <string to replace> <string to replace with>";
	else if (msg == ERR_OPEN_I)
		std::cerr << "Failed to open infile, check if the file exists and readable";
	else if (msg == ERR_OPEN_O)
		std::cerr << "Failed to open outfile, check if the file exists and writable";
	else if (msg == ERR_BIG_FILE)
		std::cerr << "File is too big";
	std::cerr << std::endl;
}
