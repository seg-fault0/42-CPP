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

void print(std::string str, const std::vector<int>& vec)
{
	std::cout << str;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

double getDuration(std::clock_t start)
{
	return (static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * 1000000); 
}