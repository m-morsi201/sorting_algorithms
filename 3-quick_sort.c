#include "sort.h"
/**
  * quick_sort - function that sorts an array of integers in ascending order
  *	using the Quick sort algorithm.
  *
  * @array: array to be sorted.
  * @size: size of array.
*/
void quick_sort(int *array, size_t size);
void sorting_alg(int *arr, int l, int r, size_t size);
int spliting(int *arr, int l, int r, size_t size);

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sorting_alg(array, 0, size - 1, size);
}

/**
  * sorting_alg - function used as recursive sorting algorithm.
  * @arr: array
  * @l: it is a left index
  * @r: it is a right index
  * @size: it is a size of array
  */
void sorting_alg(int *arr, int l, int r, size_t size)
{
	int p;

	if (l < r)
	{
		p = spliting(arr, l, r, size);
		sorting_alg(arr, l, p - 1, size);
		sorting_alg(arr, p + 1, r, size);
	}
}

/**
  * spliting - function that used to split array.
  * @arr: it is an array.
  * @l: it is a left index.
  * @r: it is a right index.
  * @size: array size.
  * Return: p index.
*/
int spliting(int *arr, int l, int r, size_t size)
{
	int iter, iter2, p, tmp;

	p = arr[r];
	iter = l;

	for (iter2 = l; iter2 < r; iter2++)
	{
		if (arr[iter2] < p)
		{
			if (iter != iter2)
			{
				tmp = arr[iter2];
				arr[iter2] = arr[iter];
				arr[iter] = tmp;
				print_array(arr, size);
			}
			iter++;
		}
	}
	if (arr[iter] != arr[r])
	{
		tmp = arr[iter];
		arr[iter] = arr[r];
		arr[r] = tmp;
		print_array(arr, size);
	}

	return (iter);
}
