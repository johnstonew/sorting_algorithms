#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion Sort
 *
 * @list: A pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
		temp = current->prev;
		current->prev = temp->prev;
		temp->prev = current;
		temp->next = current->next;
		current->next = temp;

		if (temp->next != NULL)
			temp->next->prev = temp;

		if (current->prev == NULL)
			*list = current;
	else
		current->prev->next = current;

		print_list(*list);
	}

	current = current->next;
	}
}
