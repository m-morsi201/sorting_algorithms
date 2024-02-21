#include "sort.h"

/**
 * swapping - Function to swapping two element in an array.
 * @m: The first element to swap.
 * @b: The second element to swap.
*/

void swapping(int *m, int *b)
{
	int tmp;

	tmp = *m;
	*m = *b;
	*b = tmp;
}

/**
 * selection_sort - function that sort an array of integers in ascending order
 *	using the selection sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
*/

void selection_sort(int *array, size_t size)
{
	int *low;
	size_t r, c;

	if (array == NULL || size < 2)
		return;

	for (r = 0; r < size - 1; r++)
	{
		low = array + r;
		for (c = r + 1; c < size; c++)
			low = (array[c] < *low) ? (array + c) : low;

		if ((array + r) != low)
		{
			swapping(array + r, low);
			print_array(array, size);
		}
	}
}
