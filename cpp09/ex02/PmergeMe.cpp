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

std::vector<size_t> JacobsthalOrder(size_t size)
{
	std::vector<size_t> order;
	std::vector<size_t> jacob;

	if (size == 0)
		return (order);

	jacob.push_back(1);

	size_t j0 = 0;
	size_t j1 = 1;

	while (true)
	{
		size_t next = j1 + (2 * j0);

		if (next > size)
			break;

		jacob.push_back(next);

		j0 = j1;
		j1 = next;
	}

	size_t previous = 0;

	for (size_t i = 0; i < jacob.size(); i++)
	{
		size_t current = jacob[i];

		for (size_t k = current; k > previous; --k)
			order.push_back(k - 1);

		previous = current;
	}

	for (size_t k = size; k > previous; --k)
		order.push_back(k - 1);

	return (order);
}
