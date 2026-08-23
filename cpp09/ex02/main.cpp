#include "PmergeMe.hpp"

/******************************************************/
/*****************       PARSER     *******************/
/******************************************************/

template <typename IntContainer>
IntContainer ft_parse(int ac, char **av)
{
	IntContainer parsed;

	for (int i = 1; i < ac; ++i)
	{
		std::stringstream ss(av[i]);
		long value;

		while (ss >> value)
		{
			if (value < 0 || value > INT_MAX)
				throw std::runtime_error("Invalid number");

			parsed.push_back(static_cast<int>(value));
		}

		if (!ss.eof())
			throw std::runtime_error("Invalid input");
	}

	return (parsed);
}

/******************************************************/
/***************       Pair Maker     *****************/
/******************************************************/

template <typename PairContainer, typename IntContainer>
PairContainer makeSortPairs(const IntContainer& input)
{
	PairContainer pairs;

	for (size_t i = 0; i < input.size(); i += 2)
	{
			if (input[i] > input[i + 1])
			pairs.push_back((Pair){input[i], input[i + 1]});
		else
			pairs.push_back((Pair){input[i + 1], input[i]});
	}
	return (pairs);
}

/******************************************************/
/************       Insert Algorithm      *************/
/******************************************************/

template <typename IntContainer>
void binaryInsert(IntContainer& chain, int value, int end)
{
	size_t left = 0;
	size_t right = end;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;

		if (chain[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	chain.insert(chain.begin() + left, value);
}

template <typename IntContainer>
size_t lowerBound(const IntContainer& result, int value)
{
	size_t left = 0;
	size_t right = result.size();

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;

		if (result[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}

	return left;
}

template <typename PairContainer, typename IntContainer>
IntContainer insertPend(const IntContainer& main, const IntContainer& pend, int stragller, const PairContainer& pairs)
{
	IntContainer result(main);

	int jacob[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 
		1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};

	size_t jacob_size = sizeof(jacob) / sizeof(jacob[0]);

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

			size_t end = lowerBound(result, pairs[idx].big);
			binaryInsert(result, pend[idx], end);
		}
	}
	if (stragller != -1)
		binaryInsert(result, stragller, result.size());

	return(result);
}

/******************************************************/
/******************       Sort     ********************/
/******************************************************/

template <typename PairContainer, typename IntContainer>
IntContainer sort(IntContainer input)
{
	if (input.size() <= 1)
		return (input);

	int stragler = -1;
	if ((input.size() % 2) != 0)
	{
		stragler = input.back();
		input.pop_back();
	}
	
	PairContainer pairs = makeSortPairs<PairContainer>(input);

	IntContainer main, pend;
	for(size_t i = 0; i < pairs.size(); i++)
	{
		main.push_back(pairs[i].big);
		pend.push_back(pairs[i].small);
	}

	main = sort<PairContainer, IntContainer>(main);
	main = insertPend(main, pend, stragler, pairs);

	return  (main);
}

/******************************************************/
/******************       Main     ********************/
/******************************************************/

int main(int ac, char** av)
{ 
	if (ac <= 1)
		return (std::cerr << "Error : usage : ./PmergeMe <args>\n", 1);

	try
	{
		std::vector<int> vec = ft_parse<std::vector<int> > (ac, av);
		std::deque<int> deq = ft_parse<std::deque<int> > (ac, av);

		print("Before : ", vec);	

		std::clock_t vec_start = std::clock();
		vec = sort<std::vector<Pair> >(vec);
		double vec_dur = getDuration(vec_start);
	
		std::clock_t deq_start = std::clock();
		deq = sort<std::deque<Pair> >(deq);
		double deq_dur = getDuration(deq_start);
	
		print("After  : ", vec);
		std::cout << "Time to process a range of " << vec.size() << " elements with std::[vector] : " << vec_dur << " us" << std::endl;
		std::cout << "Time to process a range of " << vec.size() << " elements with std::[deque] : " << deq_dur << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
