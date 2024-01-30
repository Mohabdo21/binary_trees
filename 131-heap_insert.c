#include "binary_trees.h"
/**
 * swap_values - This function swaps values in the heap
 *
 * @v1: a pointer to the value to be swapped
 * @v2: a pointer to the value to be swapped
 */
void swap_values_heap(heap_t *v1, heap_t *v2)
{
	int x;

	x = v1->n;
	v1->n = v2->n;
	v2->n = x;
}

/**
 * heapify - Builds the maxheap using the sift-down heap sort algorithm
 * Note: each time 2 elements are swapped, the array is printed
 * @array: pointer to the array of integers to be sorted
 * @n: limit of unsorted subarray
 * @P: index of parent node
 * @size: size of the array
 */
void heapify(heap_t *P)
{
	if (!P || !P->parent || P->parent->n > P->n)
		return;
	swap_values_heap(P, P->parent);
	heapify(P->parent);
}
/**
 * find_last_parent - find last parent in heap
 * @root: root of heap
 * Return: pointer to last element
 */
heap_t *find_last_parent(heap_t *root)
{
	int start = 0, end = 0;
	heap_t *queue[1024];

	if (!root)
		return (0);

	queue[end++] = root;
	while (start < end)
	{
		heap_t *node = queue[start++];

		if (node->left)
			queue[end++] = node->left;

		if (node->right)
			queue[end++] = node->right;
	}
	return queue[(end + 1) / 2 - 1];
}
/**
 * bst_insert - insert value in a BST
 * @tree: double pointer to root node of BST
 * @value: value to store in the node to be inserted
 * Return: pointer to new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = NULL, *parent = (*root);

	if (!root || !(*root))
	{
		node = binary_tree_node(parent, value);
		(*root) = node;
	}
	else
	{
		parent = find_last_parent(*root);
		node = binary_tree_node(parent, value);
		if (!parent->left)
		{
			parent->left = node;
		}
		else
		{
			parent->right = node;
		}
		heapify(node);
	}

	return (node);

}
