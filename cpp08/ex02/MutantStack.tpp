#include "MutantStack.hpp"

/*********************************************/
/*************     ORTHODOX    ***************/
/*********************************************/

template<class T>
MutantStack<T>::MutantStack() : std::stack<T>::stack() {}

template<class T>
MutantStack<T>::~MutantStack() {}

template<class T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>::stack(other)
{
	*this = other;
}

template<class T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other)
	{
		std::stack<T>::operator=(other);
	}
	return (*this);
}

/*********************************************/
/*************      METHODS    ***************/
/*********************************************/

///////	begin/end
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

//////// const begin/end

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

///////	rbegin/rend

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

/////// const rbegin/rend

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (this->c.rend());
}