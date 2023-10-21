#include "sort.h"

/**
 * swap - swap 2 elements from arr
 * @arr: arr
 * @a: a
 * @b: b
 */
void swap(int *arr, int a, int b)
{
	int temp = arr[a];

	arr[a] = arr[b];
	arr[b] = temp;
}

/**
 * partition - partition helper function
 * @array: array
 * @size: size
 * @original: original
 * @osize: osize
 * Return: pivot index
 */
size_t partition(int *array, size_t size, int *original, size_t osize)
{
	int pivot = array[size - 1];
	size_t i = -1;
	size_t j;

	for (j = 0; size > j; j++)
	{
		if (array[j] <= pivot)
		{
			i++;

			if (j != i)
			{
				swap(array, i, j);
				print_array(original, osize);
			}
		}
	}

	return (i);
}

/**
 * sortQuick - partial quicksort
 * @array: array
 * @size: size
 * @original: original
 * @osize: osize
 */

void sortQuick(int *array, size_t size, int *original, size_t osize)
{
	size_t pi;

	if (size < 2 || !array)
		return;

	pi = partition(array, size, original, osize);

	sortQuick(array, pi, original, osize);
	sortQuick(array + pi, size - pi - 1, original, osize);
}

/**
 * quick_sort - Quick Sorting Arrays
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sortQuick(array, size, array, size);
}
