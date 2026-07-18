#pragma once

//libraries
# include <iostream>
# include <fstream>
# include <stdexcept>
# include <map>
# include <string>
# include <sstream>

//macros
# define DATA_FILE "data.csv"

//class
class BitcoinExchange
{
	private:
		std::ifstream					_inputFile;
		std::map<std::string, float>	_dataBaseMap;

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