#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac <= 1)
		return (std::cerr << "Error : usage : ./PmergeMe <args>\n", 1);
	
	try
	{
		PmergeMe<std::vector<std::pair<int, int> >, std::vector<int> > vect;
		PmergeMe<std::deque<std::pair<int, int> >, std::deque<int> > deq;

		vect.init(ac, av);
		deq.init(ac, av);

		vect.lunch();
		deq.lunch();

		std::cout << "before: " << vect.getBefore() << std::endl;
		std::cout << "after : " << vect.getAfter() << std::endl;
		std::cout << "Time to process a range of " << vect.getSize() << " elements with  std::vector : " << vect.getTime() << " us" << std::endl;
		std::cout << "Time to process a range of " << deq.getSize() << " elements with  std::deque : " << deq.getTime() << " us" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}