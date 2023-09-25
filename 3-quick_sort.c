#include "sort.h"
#include <stddef.h>

void swap(int *arr_elem_one, int *arr_elem_two);
int partition(int *array, int start_idx, int end_idx,
	      int *original_array, int original_size);
void quick_sort_pro(int *array, size_t size,
		    int *original_array, size_t original_size);

/**
 * swap - Function that swaps two arrays
 *
 * @arr_elem_one: pointer to first array element to swap
 * @arr_elem_two: pointer to second array element to swap
 */
void swap(int *arr_elem_one, int *arr_elem_two)
{
	int temp;

	temp = *arr_elem_one;
	*arr_elem_one = *arr_elem_two;
	*arr_elem_two = temp;
}

/**
* partition - Function that partitions an array, moving
* elements greater than the pivot to the right and elements
* less than pivot to the left, and pivot in the middle
*
* @array: array to be partitioned
* @start_idx: start index of array
* @end_idx: end index of array
* @original_array: original array (i.e full array)
* @original_size: original array size
*
* Return: index of pivot
*/

int partition(int *array, int start_idx, int end_idx,
	      int *original_array, int original_size)
{
	int i = start_idx - 1;
	int j;

	for (j = start_idx; j < end_idx; j++)
	{
		if (array[j] < array[end_idx])
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(original_array, original_size);
		}
	}
	/* swap pivot to correct position */
	swap(&array[i + 1], &array[end_idx]);
	if ((i + 1) != end_idx)
		print_array(original_array, original_size);

	return (i + 1);
}


/**
 * quick_sort_pro - implements the quick sort algorithm, keepint track
 * of the original array and original array size
 *
 * @array: array to be sorted
 * @size: size of array to be sortes
 * @original_array: original array (i.e full array)
 * @original_size: original array size
 */

void quick_sort_pro(int *array, size_t size,
		    int *original_array, size_t original_size)
{
	int pivot_idx;

	if (array == NULL || size < 2)
		return;

	pivot_idx = partition(array, 0, size - 1,
		       original_array, original_size);

	/* quick sort left partition */
	quick_sort_pro(array, pivot_idx, original_array, original_size);
	/* quick sort right partition */
	quick_sort_pro(array + pivot_idx + 1, size - pivot_idx - 1,
		original_array, original_size);
}

/**
* quick_sort - Function that sorts array of integers
* in ascending order using the quick sort algorithm
*
* @array: Array to be sorted
* @size: Size of array
*/

void quick_sort(int *array, size_t size)
{
	int *original_array = array;
	int original_size = size;

	quick_sort_pro(array, size, original_array, original_size);
}

