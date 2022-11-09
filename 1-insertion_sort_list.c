#include "sort.h"
#include <stdlib.h>


/**
 * insertion_sort_list - sort list with insertion sort
 * @list: list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = malloc(sizeof(listint_t));
	listint_t *item = malloc(sizeof(listint_t));
	listint_t *current_list = *list;

	if (list == NULL)
		return;

	if (current_list == NULL)
		return;

	while (current_list != NULL)
	{
		item = current_list;
		if (item->prev != NULL)
		{
			while (item->prev->n > item->n)
			{
				temp = item->prev;
				temp->next = item->next;

				item->next = temp;
				item->prev = temp->prev;

				temp->prev = item;

				print_list((const listint_t *)current_list);
			}
		}
		current_list = current_list->next;
	}
}
