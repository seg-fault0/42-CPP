#pragma once

//libararies
# include <exception>
# include <algorithm>

//exception class
class NotFoundExeption : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number not found");
		}
};

//easyfind template
template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw (NotFoundExeption());
	return (it);
};
