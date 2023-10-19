#include "sort.h"

/**
 * listlen - list length
 * @head: head
 * Return: length
 */

int listlen(listint_t *head)
{
	listint_t *h = head;
	int len = 0;

	while (h)
		len++, h = h->next;

	return (len);
}

/**
 * insertion_sort_list - insertion-sorting lists
 * @list: the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cnode, *prev, *temp;

	if (!list || !*list || listlen(*list) < 2)
		return;

	cnode = (*list)->next;

	while (cnode)
	{
		prev = cnode->prev;

		temp = cnode;

		while (prev && cnode->n < prev->n)
		{
			if (cnode->next)
				cnode->next->prev = prev;
			cnode->prev = prev->prev;
			prev->next = cnode->next;
			cnode->next = prev;

			if (prev->prev)
				prev->prev->next = cnode;
			else
				*list = cnode;

			prev->prev = cnode;

			temp = prev;

			prev = cnode->prev;

			print_list(*list);
		}

		cnode = temp;
		cnode = cnode->next;
	}
}
