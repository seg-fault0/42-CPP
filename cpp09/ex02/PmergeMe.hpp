#pragma once

//libraries
# include <vector>
# include <iostream>
# include <sstream>
# include <climits>
# include <stdexcept>

//class
class PmergeMe
{
/** private member variables **/
	private:
		std::vector<std::pair<int, int> >	_elements;
		std::vector<int>					_chain;
		std::vector<int>					_pend;
		bool								_hasStraggler;
		int									_straggler;

/** private member functions **/
	private:
	//sort
		void	binaryInsert(int value);
		void	insertPendElements(std::vector<size_t> order);
		void	buildMainChain(void);
		void	merge(size_t left, size_t mid, size_t right);
		void	mergeSort(size_t left, size_t right);
		void	swap_sortPairs(void);
		void	sort(void);

/** public member functions **/
	public:
	//orthodox;
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

	//methods
		void	printElements(void) const;
		void	init(int ac, char** av);
		void	lunch(void);
	
	//exception
		class BadNumberRange : public std::exception
		{
			const char* what() const throw();
		};

		class BadInput : public std::exception
		{
			const char* what() const throw();
		};
};
