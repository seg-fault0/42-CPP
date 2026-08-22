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

std::vector<int> ft_parse(int ac, char** av)
{
	bool 				lock = false;
	std::vector<int>	parsed;

	for (int i = 1; i < ac; i++)
	{
		std::stringstream ss(av[i]);
		std::string line;

		while (std::getline(ss, line, ' '))
		{
			if (line.empty())
				continue;
			else
				parsed.push_back(ft_atoi(line));
		}
	}
	return(parsed);
}

std::vector<std::pair<int, int> > makeSortPairs(std::vector<int> input)
{
	std::vector<std::pair<int, int> > pairs;

	for (size_t i = 0; i < input.size(); i += 2)
	{
		int first = input[i];
		int second = input[i + 1];

		if (first > second)
			std::swap(first, second);
		
		pairs.push_back(std::pair<int, int>(first, second));
	}
	return (pairs);
}

std::vector<int> insertPend(std::vector<int> main, std::vector<int> pend, int stragller)
{
	std::vector<int> result(main);

	int jacob[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	int jacob_size = sizeof(jacob) / sizeof(jacob[0]);

	for (size_t jacob_i = 0; jacob_i + 1 < jacob_size; jacob_i++)
	{
		size_t group_start = jacob[jacob_i];
		size_t group_end = jacob[jacob_i + 1];

		if (group_start >= pend.size())
			break;

		if (group_end > pend.size())
			group_end = pend.size();

		while (group_end > group_start)
		{
			size_t idx = --group_end;
			std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(),  pend[idx]);
			result.insert(pos,  pend[idx]);
		}
	}
	if (stragller != -1)
	{
		std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(),  stragller);
		result.insert(pos,  stragller);
	}
	return(result);
}

std::vector<int> sort(std::vector<int> input)
{
	if (input.size() <= 1)
		return (input);

	int stragler = -1;

	if ((input.size() % 2) != 0)
	{
		stragler = input.back();
		input.pop_back();
	}
	
	std::vector<std::pair<int, int> > pairs = makeSortPairs(input);

	std::vector<int> main, pend;
	for(size_t i = 0; i < pairs.size(); i++)
	{
		main.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}

	main = sort(main);

	main = insertPend(main, pend, stragler);

	return  (main);
}