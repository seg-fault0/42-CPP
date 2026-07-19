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
	private:
		std::vector<std::pair<int, int> >	_elements;
		bool								_hasStraggler;
		int									_straggler;

	public:
	//orthodox;
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

	//methods
		void	printElements(void) const;
		void	sort(void);
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
