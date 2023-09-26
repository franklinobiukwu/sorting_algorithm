#include "sort.h"


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
* @array: array to be sorted
* @size: size of array
*/

void shell_sort(int *array, size_t size)
{
	int i, j, k;
	int gap = 1, flag = 0;

	if (array == NULL || size < 2)
		return;

	while (gap < (int)size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = 0, j = gap; j < (int)size; i++, j++)
		{
			if (array[i] > array[j])
			{
				swap(&array[i], &array[j]);
				flag = 1;
			}

			if (flag == 1)
			{
				k = i;
				while ((k - gap) >= 0)
				{
					if (array[k - gap] > array[k])
					{
						swap(&array[k - gap], &array[k]);
					}
					k = k - gap;
				}
			}
			flag = 0;
		}

		gap = gap / 3;
		print_array(array, size);
	}
}
