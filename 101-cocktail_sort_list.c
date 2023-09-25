#include "sort.h"

/**
 * swap_node - function to swap values in list
 * @list: array containing the elements
 * @first_node: first node to be compared arguement
 * @second_node: second  node to be compared arguement
 * Return: Void
*/

void swap_node(listint_t **list, listint_t *first_node, listint_t *second_node)
{
	if (*list == NULL || first_node == NULL || second_node == NULL)
		return;

	if (first_node->prev != NULL)
	{
		first_node->prev->next = second_node;
	}
	if (second_node->next != NULL)
	{
		second_node->next->prev = first_node;
	}
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	first_node->prev = second_node;
	second_node->next = first_node;

	if (first_node == *list)
	{
		*list = second_node;
	}
}

/**
 * cocktail_sort_list - Implementation of the cocktail sort algorithm
 * @list: array containing unsorted elements
 * Return: Void
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL, *end = NULL;

	/*If list provided is empty - actions to take*/
	if (*list == NULL || list == NULL)
		return;
	while (swapped) /*If we assume that a swap will occur*/
	{
		start = (*list); /*assign the start of array to start*/
		swapped = 0; /*set swap to 0 (no swap)*/

		while (start->next != NULL) /*while list has more than 2 values*/
		{
			if (start->n > start->next->n) /*compare first value and the next value*/
			{
				swap_node(list, start, start->next);/*if true, pass to swap node()*/
				swapped = 1; /*update swapped to 1 (swap happened)*/
				print_list(*list); /*print updated list*/
			}
			else
				start = start->next;/*moved to next values*/
		}
		end = start; /*end, swap directions*/
		if (!swapped) /*if swap doesnt occur, break loop*/
			break; /*means its sorted*/
		swapped = 0;/*reset swap, for opposite direction*/
		end = end->prev; /*end my equal second to last value*/
		while (end->prev != start) /*end != last value cause = sorted*/
		{
			if (end->n < end->prev->n)
			{/*end value must be smaller than the prev cause small values to the start*/
				swap_node(list, end->prev, end); /*swap nodes again*/
				swapped = 1; /*update that swap happended*/
				print_list(*list);/*print updated list*/
			}
			else
				end = end->prev; /*move backwards in array*/
		}
		start = end; /*swap directions again*/
	}
}
