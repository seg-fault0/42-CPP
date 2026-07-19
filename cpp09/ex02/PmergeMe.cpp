#include "PmergeMe.hpp"

/******************************************/
/***********     ORTHODOX    **************/
/******************************************/

int ft_atoi(const std::string& str)
{
	std::stringstream ss(str);
	long long n;
	char c;

	if (!(ss >> n) || (ss >> c))
		throw(PmergeMe::BadInput());

	if (n < 0 || n > INT_MAX)
		throw(PmergeMe::BadNumberRange());

	return static_cast<int>(n);
}

void	PmergeMe::printElements(void) const
{
	std::pair<int, int> pair;

	for(size_t i = 0; i < _elements.size(); i++)
	{
		pair = _elements[i];

		std::cout << pair.first << " " << pair.second << " ";
	}
	if (_hasStraggler == true)
		std::cout << _straggler;
}

/******************************************/
/***********     ORTHODOX    **************/
/******************************************/

PmergeMe::PmergeMe() : _hasStraggler(false), _straggler(0){}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void) other;
	return (*this);
}

/******************************************/
/***********      METHODS    **************/
/******************************************/

void	PmergeMe::init(int ac, char** av)
{
	bool lock = false;
	std::pair<int, int> pair;

	for(int i = 1 ; i < ac; i++)
	{
		std::stringstream ss(av[i]);
		std::string line;

		while(getline(ss, line, ' '))
		{
			if (lock == false)
			{
				pair.first = ft_atoi(line);
				lock = true;
			}
			else
			{
				pair.second = ft_atoi(line);
				_elements.push_back(pair);
				lock = false;
			}
		}
	}
	if (lock == true)
	{
		_hasStraggler = true;
		_straggler = pair.first;
	}
}

void	PmergeMe::sort(void)
{
	std::cout << "sorting..." << std::endl;
}

void	PmergeMe::lunch(void)
{
	std::cout << "before: "; printElements(); std::cout << std::endl;
	sort();
	std::cout << "after : "; printElements(); std::cout << std::endl;
}

/******************************************/
/***********      EXCEPTION    ************/
/******************************************/

const char* PmergeMe::BadNumberRange::what() const throw()
{
	return ("0 <= nuber <= INT_MAX");
}

const char* PmergeMe::BadInput::what() const throw()
{
	return ("a non space/digit char was found");
}