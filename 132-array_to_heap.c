#include "binary_trees.h"
/**
 * array_to_heap - build a BST from an array
 * @array: pointer to the first element of array
 * @size: number of elements of array
 * Return: pointer to root node
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t i;

	if (!array || !size)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		heap_insert(&tree, array[i]);
	}


	return (tree);
}
