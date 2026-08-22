#include "PmergeMe.hpp"



int main(int ac, char** av)
{
	if (ac <= 1)
		return (std::cerr << "Error : usage : ./PmergeMe <args>\n", 1);
	
	std::vector<int> elements = ft_parse(ac, av);
	
	std::clock_t start = std::clock();

	elements = sort(elements);

	double dur =  static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * 1000000;

	for(size_t i = 0; i < elements.size(); i++)
		std::cout << elements[i] << ", ";
	std::cout << "\n";

	std::cout << "\n\ndur = " << dur;
}

