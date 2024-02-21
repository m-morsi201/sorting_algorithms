#include "sort.h"

/**
 * insertion_sort_list - Function that sort a given array using
 *	the Insertion sort algorithm in the ascending order.
 *
 * @list: pointer to the list to be sorted.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_list = NULL, *unsorted_list = NULL, *temp = NULL;

	if (list == NULL || (*list)->next == NULL)
		return;

	unsorted_list = (*list)->next;
	while (unsorted_list != NULL)
	{
		sorted_list = unsorted_list->prev;
		temp = unsorted_list->next;

		while (sorted_list != NULL)
		{
			if (unsorted_list->n < sorted_list->n)
			{
				sorted_list = sorted_list->prev;

				if (unsorted_list->next != NULL)
					unsorted_list->next->prev = unsorted_list->prev;
				unsorted_list->prev->next = unsorted_list->next;
				unsorted_list->prev = sorted_list;
				if (sorted_list == NULL)
				{
					(*list)->prev = unsorted_list;
					unsorted_list->next = *list;
					*list = unsorted_list;
				}
				else
				{
					sorted_list->next->prev = unsorted_list;
					unsorted_list->next = sorted_list->next;
					sorted_list->next = unsorted_list;
				}
				print_list(*list);
			}
			else
				break;
		}
		unsorted_list = temp;
	}
}
