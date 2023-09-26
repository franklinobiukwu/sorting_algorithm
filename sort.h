#ifndef SORT_H
#define SORT_H

#include <unistd.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;




/* Print function prototypes */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* Function prototypes for mandatory */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* Function prototypes for advanced tasks*/
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void swap_node(listint_t **list, listint_t *first_node, listint_t *second_node);
void merge_sorted_array(int *array, int left, int middle, int right);
void merge_sort_recursion(int *array, int left, int right);
void merge_sort(int *array, size_t size);

#endif
