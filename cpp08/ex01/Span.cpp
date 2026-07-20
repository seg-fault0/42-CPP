#include "Span.hpp"

/***********************************************/
/**************     ORTHODOX     ***************/
/***********************************************/

Span::Span() : N(0) {}

Span::~Span() {}

Span::Span(const Span& other) { *this = other; }

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		N = other.N;
		_v = other._v;
	}
	return (*this);
}

/***********************************************/
/*********     OTHER CONSTRUCTORS     **********/
/***********************************************/

Span::Span(unsigned int n) : N(n) {}

/***********************************************/
/***************     METHODS     ***************/
/***********************************************/

void	Span::addNumber(int n)
{
	if (_v.size() >= N)
		throw (FullContainer());
	_v.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > N)
		throw (FullContainer());
	_v.insert(_v.end(), begin, end);
}

int	Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw (NotEnoughNumbers());

	std::vector<int> buffer = _v;
	std::sort(buffer.begin(), buffer.end());
	
	int dif = buffer[1] - buffer[0];
	for(unsigned int i = 0; i < buffer.size() - 1; i++)
	{
		if (dif > (buffer[i + 1] - buffer[i]))
			dif = buffer[i + 1] - buffer[i];
	}
	return (dif);
}

int	Span::longestSpan()
{
	if (_v.size() <= 1)
		throw (NotEnoughNumbers());
	
	std::vector<int> buffer = _v;
	std::sort(buffer.begin(), buffer.end());

	return (buffer[buffer.size() - 1] - buffer[0]);
}

/***********************************************/
/**************     EXCEPTION     **************/
/***********************************************/

const char* Span::FullContainer::what() const throw()
{
	return ("Container is full");
}

const char* Span::NotEnoughNumbers::what() const throw()
{
	return ("container has n <= 1 numbers, not enough !!");
}