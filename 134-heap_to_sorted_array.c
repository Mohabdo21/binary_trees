#include "binary_trees.h"
/*/1** */
/* * binary_tree_node - create a binary tree node */
/* * @parent: Pointer to the parent node */
/* * @value: Integer stored in the node */
/* * Return: Pointer to the new node */
/* *1/ */
/*binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) */
/*{ */
/*	binary_tree_t *node = malloc(sizeof(binary_tree_t)); */

/*	if (!node) */
/*		return (NULL); */
/*	node->n = value; */
/*	node->left = NULL; */
/*	node->right = NULL; */
/*	node->parent = parent; */

/*	return (node); */
/*} */

/**
 * heap_to_sorted_array - convert a max heap into a sorted array (DESC)
 * @heap: pointer to the root of the heap
 * @size: pointer to store size of array
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
	sorted = realloc(sorted, sizeof(int) * *size);
	return (sorted);
}
