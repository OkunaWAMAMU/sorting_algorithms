#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers
 * @list: The doubly linked list to be printed
 */
void print_list(const listint_t *list)
{
    int first = 1;

    while (list)
    {
        if (!first)
            printf(", ");
        printf("%d", list->n);
        first = 0;
        list = list->next;
    }
    printf("\n");
}
