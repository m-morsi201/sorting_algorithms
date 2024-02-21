#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers in ascending order
 *	using the Bubble sort algorithm.
 *
 * @array: It is a pointer to an array.
 * @size: It is a size of the array.
*/

void bubble_sort(int *array, size_t size)
{
	size_t r, c, num;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (r = 0; r < size; r++)
	{
		for (c = 1; c < size - r; c++)
		{
			if (array[c - 1] > array[c])
			{
				num = array[c];
				array[c] = array[c - 1];
				array[c - 1] = num;
				print_array(array, size);
			}
		}
	}
}
