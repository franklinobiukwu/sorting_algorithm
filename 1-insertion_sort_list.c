#include "sort.h"

/**
 * insertion_sort_list - Implementation of insertion sort algorithm
 * @list: A pointer to a pointer at the head of a linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted, *current, *temp, *sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	unsorted = (*list)->next;

	while (unsorted != NULL)
	{
		sorted = unsorted->prev;
		current = unsorted;

		while (sorted != NULL && current->n < sorted->n)
		{
			temp = sorted->prev;
			if (current->next != NULL)
			{
				current->next->prev = sorted;
			}
			sorted->next = current->next;
			sorted->prev = current;
			if (temp != NULL)
			{
				temp->next = current;
			}
			else
			{
				*list = current;
			}
			current->prev = temp;
			current->next = sorted;
			print_list(*list);
			sorted = temp;
		}
		unsorted = unsorted->next;
	}
}
