#include "sort.h"

/**
 * find_max - find largest integer element in an array
 *
 * @array: arry
 * @size: size of array
 *
 * Return: maximum element
 */

int find_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	/* Determine maximum element in array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* return maximum number */
	return (max);
}

/**
* counting_sort - Function that sorts integer elements of an array
* in ascending order
*
* @array: array to be sorted
* @size: size of array
*
*/

void counting_sort(int *array, size_t size)
{
	int k, i, idx;
	int *count_arr, *sorted_arr;

	k = find_max(array, size);/* Determine the largest value in array*/

	/* Create memory for counting array */
	count_arr = malloc(sizeof(int) * (k + 1));
	if (count_arr ==  NULL)
		return;
	for (i = 0; i <= k; i++)/* Initialize counting array */
		count_arr[i] = 0;
	/*
	 * Loop through array increment equivalent
	 * count_arr index for each element in array
	 */
	for (i = 0; i < (int)size; i++)
		count_arr[array[i]] += 1;
	/*
	 * Modify count_arr to have the actual
	 * end index of unique elements of array
	*/
	for (i = 1; i <= k; i++)
		count_arr[i] += count_arr[i - 1];
	print_array(count_arr, (k + 1));
	sorted_arr = malloc(sizeof(int) * size);/* Create sorted array */
	if (sorted_arr == NULL)
		return;
	/* Loop from end of array and write values in sorted_arr*/
	for (i = size - 1; i >= 0; i--)
	{
		idx = count_arr[array[i]] -= 1;
		sorted_arr[idx] = array[i];
	}
	/* replace values in array with values in sorted_arr*/
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_arr[i];
	free(sorted_arr);
	free(count_arr);
}
