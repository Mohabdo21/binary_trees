#include "binary_trees.h"

/**
 * sorted_array_to_avl_h - Helper function that builds an AVL tree
 *							from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @start: The starting index of the subarray to be converted.
 * @end: The ending index of the subarray to be converted.
 * Return: Pointer to the root node of the created AVL tree,
 *			or NULL on failure.
 */
avl_t *sorted_array_to_avl_h(int *array, size_t start, size_t end)
{
	size_t mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	node = binary_tree_node(NULL, array[mid]);
	if (!node)
		return (NULL);

	if (mid != start)
		node->left = sorted_array_to_avl_h(array, start, mid - 1);
	if (mid != end)
		node->right = sorted_array_to_avl_h(array, mid + 1, end);

	if (node->left)
		node->left->parent = node;
	if (node->right)
		node->right->parent = node;

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 * Return: Pointer to the root node of the created AVL tree,
 *			or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
		return (NULL);

	return (sorted_array_to_avl_h(array, 0, size - 1));
}
