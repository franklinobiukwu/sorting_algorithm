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
 * @list: pointer to a doubly linked list of integers
 * Return: Void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL, *end = NULL;

	/*If list is provided is empty*/
	if (*list == NULL || list == NULL)
		return;

	while (swapped) /*If we assume that a swap will occur*/
	{
		swapped = 0; /*set swap to 0 (no swap)*/
		start = (*list); /*start given head value*/
		end = NULL; /*end if given NULL*/
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_node(list, start, start->next);
				swapped = 1;
				print_list(*list);
			}
			else
				start = start->next;
		}
		if (!swapped) /*check is swap occured*/
			break;
		swapped = 0; /*reset of swap*/
		end = start; /*Swapping directions */

		while (end->prev != NULL) /*That end actually points to values that exist*/
		{
			if (end->n < end->prev->n)
			{
				swap_node(list, end->prev, end);
				swapped = 1;
				print_list(*list);
			}
			else
				end = end->prev;
		}
	}
}

