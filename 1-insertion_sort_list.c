#include "sort.h"

/**
 * insertion_sort_list - insertion-sorting lists
 * @list: the list
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *cnode = (*list)->next, *prev;

    while (cnode)
    {
        prev = cnode->prev;

        while (prev && cnode->n < prev->n)
        {
            cnode->next->prev = prev;
            /* Swaping nodes - cnode with it previous (rest is in bottom)*/
            cnode->prev = prev->prev;
            prev->next = cnode->next;
            cnode->next = prev;

            /* Updating prev previous node to link to cnode (current node)*/
            if (prev->prev)
                prev->prev->next = cnode;
            else
                *list = cnode;

            /* Last thing to finish swaping nodes (rest) */
            prev->prev = cnode;

            prev = cnode->prev;

            print_list(*list);
        }

        cnode = cnode->next;
    }
}