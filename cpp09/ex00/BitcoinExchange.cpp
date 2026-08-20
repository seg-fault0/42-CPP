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

bool isValidDate(const std::string& date)
{
	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return false;
	}

	long year = ft_atod(date.substr(0, 4).c_str());
	long month = ft_atod(date.substr(5, 2).c_str());
	long day = ft_atod(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

bool isValidBalance(const std::string& balance)
{
	std::stringstream ss(balance);
	double value;
	char extra;

	if (!(ss >> value) || ss >> extra)
		return false;

	if (value < MIN_BLANACE)
		throw (std::string("Error: not a positive number."));
	else if (value > MAX_BALANCE)
		throw (std::string("Error: too large a number."));

	return true;
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

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
	if (this != &other)
		_dataBaseMap = other._dataBaseMap;

	return (*this);
}

/****************************************/
/************      INIT      ************/
/****************************************/

void BitcoinExchange::init(const std::string& file)
{
	_inputFile.open(file.c_str());
	if (!_inputFile.is_open())
		throw(FileNotOpen());

	std::ifstream dataBaseFile(DATA_FILE);
	if (!dataBaseFile.is_open())
		throw(FileNotOpen());

	std::string	line, date, rate;

	std::getline(dataBaseFile, line);

	while (std::getline(dataBaseFile, line))
	{
		std::stringstream ss(line);

		if (!std::getline(ss, date, ',') || !std::getline(ss, rate))
			continue;
		if (!isValidDate(date))
			throw(InvalidDate());
		_dataBaseMap[date] = ft_atod(rate.c_str());
	}

	dataBaseFile.close();
}

/****************************************/
/************      LUNCH      ***********/
/****************************************/

void BitcoinExchange::lineHandler(std::string& line)
{
	std::stringstream	ss(line);
	std::string			date, balance;

	if (!std::getline(ss, date, '|'))
		throw ("Error: bad input => " + line);

	if (date.empty() || date[date.size() - 1] != ' ')
		throw ("Error: bad input => " + line);
	
	date.erase(date.size() - 1);

	if (!isValidDate(date))
		throw ("Error: bad input => " + line);

	if (!std::getline(ss, balance))
		throw ("Error: bad input => " + line);
	
	if (balance.size() < 2 || balance[0] != ' ')
		throw ("Error: bad input => " + line);
	balance.erase(0, 1);

	if (!isValidBalance(balance))
		throw ("Error: bad input => " + line);

	mapit it = _dataBaseMap.lower_bound(date);
	if (it == _dataBaseMap.end() || it->first != date)
	{
		if (it == _dataBaseMap.begin())
			throw ("Error: bad input => " + line);
		--it;
	}
	std::cout << date << " => " << ft_atod(balance) << " = " << it->second * ft_atod(balance) << std::endl;
}

void BitcoinExchange::lunch(void)
{
	std::string			line;

	std::getline(_inputFile, line);
	if (line != "date | value")
		throw(InvalidFirstLine());

	while (std::getline(_inputFile, line))
	{
		try
		{
			lineHandler(line);
		}
		catch(const std::string& e)
		{
			std::cout << e << '\n';
		}
	}
}

/****************************************/
/************    EXCEPTION   ************/
/****************************************/

const char* BitcoinExchange::FileNotOpen::what() const throw()
{
	return ("Error: could not open file.");
}

const char* BitcoinExchange::InvalidDate::what() const throw()
{
	return ("Error: invalide date in database file.");
}

const char* BitcoinExchange::InvalidFirstLine::what() const throw()
{
	return ("Error: invalid first line.");
}
