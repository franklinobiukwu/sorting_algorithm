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

	/* Generate gap interval */
	while (gap < (int)size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		/* Pass throgh array and compare two distant(gap) elements */
		for (i = 0, j = gap; j < (int)size; i++, j++)
		{
			/* Swap compared element if lesser element is at the RHS*/
			if (array[i] > array[j])
			{
				swap(&array[i], &array[j]);
				flag = 1;
			}

			 /*if swap, compare swapped RHS element with more LHS element*/
			if (flag == 1)
			{
				k = i;
				while ((k - gap) >= 0)
				{
					/* Swap if LHS element is greater than swapped RHS element */
					if (array[k - gap] > array[k])
						swap(&array[k - gap], &array[k]);
					k = k - gap;
				}
			}
			flag = 0;
		}

		gap = gap / 3;
		print_array(array, size);
	}
}
