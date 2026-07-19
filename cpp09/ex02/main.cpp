#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac <= 1)
		return (std::cerr << "Error : usage : ./PmergeMe <args>\n", 1);
	
	try
	{
		PmergeMe pmergeme;

		pmergeme.init(ac, av);
		pmergeme.lunch();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}