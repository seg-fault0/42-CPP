#pragma once

#include "Array.hpp"

/*************************************/
/***********    ORTHODOX   ***********/
/*************************************/

template <class T>
Array<T>::Array()
{
	elements = NULL;
	_size = 0;
}

template <class T>
Array<T>::~Array()
{
	delete[] elements;
}

template <class T>
Array<T>::Array(const Array& other)
{
	elements = NULL;
	_size = 0;
	*this = other;
}

template <class T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] elements;
		_size = other._size;
		elements = new T[other._size];
		for(unsigned int i = 0; i < other._size; i++)
			elements[i] = other.elements[i];
	}
	return (*this);
}

/*************************************/
/*******   OTHER CONSTRUCTORS   ******/
/*************************************/

template <class T>
Array<T>::Array(unsigned int size)
{
	elements = new T[size];
	_size = size;
}

/*************************************/
/***********    OVERLOAD   ***********/
/*************************************/

template <class T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw(OutOfBound());
	return (elements[i]);
}

template <class T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw(OutOfBound());
	return (elements[i]);
}

/*************************************/
/***********     GETERS    ***********/
/*************************************/

template <class T>
unsigned int Array<T>::size(void) const { return (_size); }

/*************************************/
/**********    EXCEPTION    **********/
/*************************************/

template <class T>
const char* Array<T>::OutOfBound::what() const throw()
{
	return ("Array out of bound");
}