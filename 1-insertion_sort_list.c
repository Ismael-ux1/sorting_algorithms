#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;

if (!list || !(*list) || !(*list)->next)
return;

current = (*list)->next;
while (current)
{
temp = current;
while (temp->prev && temp->n < temp->prev->n)
{
temp->prev->next = temp->next;
if (temp->next)
temp->next->prev = temp->prev;
temp->next = temp->prev;
temp->prev = temp->prev->prev;
temp->next->prev = temp;
if (!temp->prev)
*list = temp;
else
temp->prev->next = temp;
print_list(*list);
}
current = current->next;
}
}

/**
 * swap - swaps 2 values
 * @a: the first int
 * @b: the seconde int
 * Reuturn: void
*/
void swap(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}
