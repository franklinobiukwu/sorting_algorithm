#include "sort.h"
#include <stdio.h>



/**
 * swap - swaps elements of array
 *
 * @elem_one: pointer to first array element
 * @elem_two: pointer to second element
 */

void swap(int *elem_one, int *elem_two)
{
	int temp = *elem_one;
	*elem_one = *elem_two;
	*elem_two = temp;
}

/**
* shell_sort - sort array of integers using the shell sort algorithm
*
* @array - array to be sorted
* @size - size of array
*/

void shell_sort(int *array, size_t size)
{
	size_t i;
	size_t gap = 1;

	if (array == NULL || size < 2)
		return;
	
	while (gap < size)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		printf("Gap is: %ld\n", gap);
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[gap + i])
			{
				swap(&array[i], &array[gap]);
				print_array(array, size);
			}
		}

		gap = gap/3;
	}
}
