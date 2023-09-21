#include "sort.h"

/**
 * bubble_sort - Implementation of the bubble sorting algorithm
 * @array: This is the array to be sorted
 * @size: Is the length of given array
 * Return: Void
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp = 0;
	int swapped;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}

}
