#pragma once

# include <stdlib.h>

template <typename T, typename F>

void	iter(T* arr, size_t size, F func)
{
	if (!arr)
		return ;
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
}
