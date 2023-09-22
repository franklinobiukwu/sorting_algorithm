#include "sort.h"

/**
* selection_sort - Sorts an array of integers in ascending order
* using the selection sort algorithm
*
* @array: Array to be sorted
* @size: Size of array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		/*
		 * Store the index of first element of the array
		 * as index of minimum element
		 */

		min_idx = i;

		/*Determine the minimum element in the array*/
		for (j = i + 1; j < size; j++)
		{
			/*
			 * Update index of minimum element
			 * if a lower integer is found
			 */

			if (array[min_idx] > array[j])
			{
				min_idx = j;
			}
		}

		/*Swap first element and minimum element*/
		temp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = temp;

		/*Print array after swap*/
		print_array(array, size);
	}
}
