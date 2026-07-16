#pragma once

//libraries
# include <stdexcept>
# include <time.h>
# include <stdlib.h>

//class
template <class T>
class Array
{
	private:
		T*				elements;
		unsigned int	_size;

	public:
	//orthodox
		Array();
		~Array();
		Array(const Array& other);
		Array& operator=(const Array& other);

	//other constructors
		Array(unsigned int n);
	
	//overload
		T& operator[](unsigned int);
		const T& operator[](unsigned int) const;

	//getes
		unsigned int	size(void) const;

	//exception
	class OutOfBound : public std::exception
	{
		const char* what() const throw();
	};
};

#include "Array.tpp"
