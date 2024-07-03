#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: The doubly linked list
 * @node1: The first node
 * @node2: The second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current;
    listint_t *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current;
        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            swap_nodes(list, temp->prev, temp);
            print_list(*list);
        }
        current = current->next;
    }
}
