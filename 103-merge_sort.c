#include "sort.h"

/**
* merge_sort - implementation on merge_sort algorithm
* @array: Pointer to unsorted array
* @size: Length of unsorted array
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	merge_sort_recursion(array, 0, size - 1);
}

/**
* merge_sort_recursion - function to break the array to sub-array portions
* @array: Pointer to unsorted array
* @left: Left portion of array
* @right: Right portion of array
*/
void merge_sort_recursion(int *array, int left, int right)
{
	int middle = 0;

	if (left < right)
	{
		middle = left + (right - left) / 2;
		merge_sort_recursion(array, left, middle);
		merge_sort_recursion(array, middle + 1, right);
		merge_sorted_array(array, left, middle, right);
	}
}

/**
* merge_sorted_array - function that merges the sorted single indexed array
* @array: Pointer to the array
* @left: Left indexed part of array
* @middle: The middle of the array
* @right: Right indexed part of array
* Return: Void
*/

void merge_sorted_array(int *array, int left, int middle, int right)
{
	int left_length = middle - left + 1;
	int right_length = right - middle;
	int i, j, k;
	int *temp_left = malloc(sizeof(int) * left_length);
	int *temp_right = malloc(sizeof(int) * right_length);

	if (temp_left == NULL || temp_right == NULL)
	{
		return;
	}
	for (i = 0; i < left_length; i++)
	{
		temp_left[i] = array[left + i];
	}
	for (j = 0; j < right_length; j++)
	{
		temp_right[j] = array[middle + 1 + j];
	}
	i = 0;
	j = 0;
	k = left;
	while (i < left_length && j < right_length)
	{
		if (temp_left[i] <= temp_right[j])
		{
			array[k] = temp_left[i];
			i++;
		}
		else
		{
			array[k] = temp_right[j];
			j++;
		}
		k++;
	}
	while (i < left_length)
	{
		array[k] = temp_left[i];
		i++;
		k++;
	}
	while (j < right_length)
	{
		array[k] = temp_right[j];
		j++;
		k++;
	}
	free(temp_left);
	free(temp_right);
}
