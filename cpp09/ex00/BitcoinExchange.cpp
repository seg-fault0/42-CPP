#include "BitcoinExchange.hpp"

/****************************************/
/************     HELPER     ************/
/****************************************/

float	ft_atof(const std::string& str)
{
	std::stringstream ss(str);
	float ret;

	ss >> ret;
	return (ret);
}

/****************************************/
/************    ORTHODOX    ************/
/****************************************/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange()
{
	if (_inputFile.is_open())
		_inputFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) { return (*this); }

/****************************************/
/************    METHODS     ************/
/****************************************/

void BitcoinExchange::init(const std::string& file)
{
	//open input file
	_inputFile.open(file.c_str());
	if (!_inputFile.is_open())
		throw(FileNotOpen());

	//open database file
	std::ifstream dataBaseFile(DATA_FILE);
	if (!dataBaseFile.is_open())
		throw(FileNotOpen());

	//read && map line
	std::string	line;
	while (std::getline(dataBaseFile, line))
	{
		std::stringstream ss(line);

		std::string date;
		std::string rate;

		std::getline(ss, date, ',');
		std::getline(ss, rate);

		_dataBaseMap[date] = ft_atof(rate.c_str());
	}

	//close
	dataBaseFile.close();
}

void BitcoinExchange::lunch(void)
{
	std::map<std::string, float>::iterator it;
	it = _dataBaseMap.begin();

	while(it != _dataBaseMap.end())
	{
		std::cout << it->first << " | " << it->second << std::endl;
		it++;
	}
}

/****************************************/
/************    EXCEPTION   ************/
/****************************************/

const char* BitcoinExchange::FileNotOpen::what() const throw()
{
	return ("Failed to open file");
}