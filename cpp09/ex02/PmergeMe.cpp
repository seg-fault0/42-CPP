#include "PmergeMe.hpp"

int ft_atoi(const std::string& str)
{
	std::stringstream ss(str);
	long long n;
	char c;

	if (!(ss >> n) || (ss >> c))
		throw(std::runtime_error("Error : bad input"));

	if (n < 0 || n > INT_MAX)
		throw(std::runtime_error("Error : bad input"));

	return (static_cast<int>(n));
}