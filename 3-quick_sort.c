#include "sort.h"

/**
 * change_position - Swaps two integers in an array.
 * @array: Array of integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * @size: Size of the array.
 */
void change_position(int *array, int *a, int *b, size_t size)
{
int exchange_position = *a;

*a = *b;
*b = exchange_position;
print_array(array, size);
}

/**
 * partition - Partition function for Quick Sort.
 * @array: Array to be sorted.
 * @low: Low index of the partition.
 * @high: High index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot after partitioning.
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int Index = low;
int i;

for (i = low; i < high; i++)
{
if (array[i] <= pivot)
{
if (Index != i)
change_position(array, &array[i], &array[Index], size);
Index++;
}
}

if (Index != high)
change_position(array, &array[high], &array[Index], size);
return (Index);
}

/**
 * quick_sort_helper - Recursive helper function for Quick Sort.
 * @array: Array to be sorted.
 * @low: Low index of the partition.
 * @high: High index of the partition.
 * @size: Size of the array.
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_index = partition(array, low, high, size);

quick_sort_helper(array, low, pivot_index - 1, size);
quick_sort_helper(array, pivot_index + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_helper(array, 0, size - 1, size);
}

