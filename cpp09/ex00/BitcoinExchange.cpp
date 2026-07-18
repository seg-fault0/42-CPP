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

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
	(void) other;
	return (*this);
}

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
	std::string			line, date, balance;
	std::stringstream	ss;

	//skip first line
	std::getline(_inputFile, line);

	//read inputFile and print
	while (std::getline(_inputFile, line))
	{
		std::stringstream ss(line);

		if (!std::getline(ss, date, '|'))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		//remove the space
		date.erase(date.size() - 1);

		//balance not found
		if (!std::getline(ss, balance))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		//check balance size
		if (ft_atod(balance) < MIN_BLANACE || ft_atod(balance) > MAX_BALANCE)
		{
			if (ft_atod(balance) < MIN_BLANACE)
				std::cerr << "Error: not a positive number." << std::endl;
			else
				std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		//check if there's is a cur/before date in database
		mapit it = _dataBaseMap.lower_bound(date);
		if (it == _dataBaseMap.end() || it->first != date)
		{
			if (it == _dataBaseMap.begin())
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			--it;
		}

		//print
		std::cout << date << " => "
				<< ft_atod(balance) << " = "
				<< it->second * ft_atod(balance)
				<< std::endl;
	}
}

/****************************************/
/************    EXCEPTION   ************/
/****************************************/

const char* BitcoinExchange::FileNotOpen::what() const throw()
{
	return ("Error: could not open file.");
}