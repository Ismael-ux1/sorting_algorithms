#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
size_t i, j, min_idx;
int temp;

for (i = 0; i < size - 1; i++)
{
min_idx = i;
for (j = i + 1; j < size; j++)
if (array[j] < array[min_idx])
min_idx = j;

if (min_idx != i)
{
temp = array[min_idx];
array[min_idx] = array[i];
array[i] = temp;
print_array(array, size);
}
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