#include "binary_trees.h"
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t i, base_size = 1024;
	int  *sorted = malloc(sizeof(int) * base_size);

	for (i = 0; heap; i++)
	{
		if (i >= base_size - 1)
		{
			base_size *= 2;
			sorted = realloc(sorted, base_size);
		}
		sorted[i] = heap_extract(&heap);
	}
	*size = i;
	return sorted;
}
