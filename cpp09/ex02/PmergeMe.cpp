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

static int ft_pow(int n, int p)
{
	int ret = 1;

	for(int i = 0; i < p; i++)
		ret *= n;
	return (n);
}

std::vector<size_t> JacobsthalOrder(size_t size)
{
	std::vector<size_t> order;

	for(int i = 0; i < size; i++)
		order.push_back((ft_pow(2, i) - ft_pow(-1, i)) / 3);
	
	return (order);
}
