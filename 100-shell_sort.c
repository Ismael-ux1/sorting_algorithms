#include "sort.h"

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

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with the Knuth sequence.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */

void shell_sort(int *array, size_t size)
{
size_t interval = 1;
size_t i, j;
int temp;

/* Generate the Knuth sequence */
while (interval <= size / 3)
interval = interval * 3 + 1;

/* Perform Shell sort with Knuth sequence */
while (interval > 0)
{
for (i = interval; i < size; i++)
{
temp = array[i];
j = i;

while (j >= interval && array[j - interval] > temp)
{
array[j] = array[j - interval];
j -= interval;
}

array[j] = temp;
}

/* Print the array after each interval pass */
print_array(array, size);

/* Reduce the interval */
interval = (interval - 1) / 3;
}
}

