#pragma once

//libraries
# include <iostream>
# include <fstream>
# include <stdexcept>
# include <map>
# include <string>
# include <sstream>
# include <climits>

//macros
# define DATA_FILE "data.csv"
# define MAX_BALANCE 1000
# define MIN_BLANACE 0

//alias types
typedef typename std::map<std::string, double>::iterator mapit;

//class
class BitcoinExchange
{
	private:
		std::ifstream					_inputFile;
		std::map<std::string, double>	_dataBaseMap;

	public:
	//orthodox
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
	
	//methods
		void	init(const std::string& file);
		void	lunch(void);
	
	//exceptiom
		class FileNotOpen : public std::exception
		{
			const char* what() const throw();
		};
};