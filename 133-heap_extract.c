#include "binary_trees.h"
/*/1** */
/* * swap_values - This function swaps values in the heap */
/* * */
/* * @v1: a pointer to the value to be swapped */
/* * @v2: a pointer to the value to be swapped */
/* *1/ */
/*void swap_values_heap(heap_t *v1, heap_t *v2) */
/*{ */
/*	int x; */

/*	x = v1->n; */
/*	v1->n = v2->n; */
/*	v2->n = x; */
/*} */

/**
 * heapify - Builds the maxheap using the sift-down heap sort algorithm
 * Note: each time 2 elements are swapped, the array is printed
 * @array: pointer to the array of integers to be sorted
 * @n: limit of unsorted subarray
 * @P: index of parent node
 * @size: size of the array
 */
void sift_down(heap_t *P)
{
	heap_t *max = P;
	if (!P)
		return;
	if (P->left && P->left->n > max->n)
	{
		max = P->left;
	}
	if (P->right && P->right->n > max->n)
	{
		max = P->right;
	}

	if (max != P)
	{
		swap_values_heap(P, max);
		sift_down(max);
	}
}
/**
 * find_last - find last parent in heap
 * @root: root of heap
 * Return: pointer to last element
 */
heap_t *find_last_level_node(heap_t *root)
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
	return queue[end - 1];
}
/**
 * bst_insert - insert value in a BST
 * @tree: double pointer to root node of BST
 * @value: value to store in the node to be inserted
 * Return: pointer to new node
 */
int heap_extract(heap_t **root)
{
	heap_t *candidate = (*root);
	int value = 0;
	if (!root || !(*root))
		return (0);
	value = candidate->n;
	candidate = find_last_level_node(*root);
	swap_values_heap((*root), candidate);
	if (candidate && candidate->parent)
	{
		if (candidate == candidate->parent->left)
			candidate->parent->left = NULL;
		else
			candidate->parent->right = NULL;
	}
	else if (candidate == *root)
		(*root) = NULL;
	free(candidate);
	candidate = NULL;
	if (*root)
		sift_down(*root);
	return value;
}
