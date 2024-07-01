#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Implements Lomuto partition scheme for quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap_ints(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (array[i + 1] != array[high])
    {
        swap_ints(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quicksort - Recursive function to perform quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);

        quicksort(array, low, pi - 1, size);
        quicksort(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm (Lomuto partition scheme)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}
