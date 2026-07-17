#pragma once

# include <vector>
# include <stdexcept>
# include <algorithm>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	_v;
	
	public:
	//orthodox
		Span();
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

	//other constructor
		Span(unsigned int n);
	
	//methods
		int		shortestSpan();
		int		longestSpan();
		void	addNumber(int n);
		void 	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	//exception
	class FullContainer : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NotEnoughNumbers : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};