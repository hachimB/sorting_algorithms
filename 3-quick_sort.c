#include "sort.h"

/**
 * swap - swap 2 elements from arr
 * @arr: arr
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
 * Return: pivot index
 */
size_t partition(int *array, size_t size)
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
                print_array(array, size);
            }
        }
    }

    return (i);
}

/**
 * quick_sort - Quick Sorting Arrays
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
    size_t pi;

    if (size < 2 || !array)
        return;

    pi = partition(array, size);

    quick_sort(array, pi);
    quick_sort(array + pi + 1, size - pi - 1);
}
