#include "sort.h"

/**
 * swap - swap 2 elements from arr
 * @arr: arr
 */

void swap(int *arr, int a, int b)
{
    int temp = arr[a];

    if (!arr || a * b < 0)
        return;

    arr[a] = arr[b];
    arr[b] = temp;
}

/**
 * partition - partition helper function
 * @array: array
 * @size: size
 * Return: pivot index
 */

size_t partition(int *array, size_t size, int *original)
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
                print_array(original, size);
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

    if (size <= 1)
        return;

    pi = partition(array, size, array);

    quick_sort(array, pi);
    quick_sort(array + pi, size - pi);
}