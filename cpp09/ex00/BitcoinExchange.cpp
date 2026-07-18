#include "BitcoinExchange.hpp"

/****************************************/
/************     HELPER     ************/
/****************************************/

double	ft_atod(const std::string& str)
{
	std::stringstream ss(str);
	double ret;

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
	std::string			line, date, rate;
	std::stringstream	ss;

	while (std::getline(dataBaseFile, line))
	{
		ss.clear();
		ss << line;

		std::getline(ss, date, ',');
		std::getline(ss, rate);

		_dataBaseMap[date] = ft_atod(rate.c_str());
	}

	//close
	dataBaseFile.close();
}

void BitcoinExchange::lunch(void)
{
	std::map<std::string, double>::iterator it;
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