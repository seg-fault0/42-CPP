#pragma once

//swap
template <typename T>
void swap(T& a, T& b)
{
	T temp = b;
	b = a;
	a = temp;
}

//min
template <typename T>
T min(const T& a, const T& b)
{
	if (a < b)
		return (a);
	return (b);
}

//max
template <typename T>
T max(const T& a, const T& b)
{
	if (a > b)
		return (a);
	return (b);
}
