#include <iostream>
#include <string.h>

template <typename A, typename C>
void	iter(A first, size_t b, C third)
{
	for (int i = 0; i < b; i++)
	{
		third((*first)[i]);
	}
}