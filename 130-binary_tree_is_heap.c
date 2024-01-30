#include "binary_trees.h"

/**
 * heap_is_complete - Checks if a heap tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or if the tree is not complete, return 0.
 *         Otherwise, return 1.
 */
int heap_is_complete(const binary_tree_t *tree)
{
	int start = 0, end = 0;
	const binary_tree_t *queue[1024];

	if (!tree)
		return (0);
	queue[end++] = tree;
	while (start < end)
	{
		const binary_tree_t *node = queue[start++];

		if (!node)
		{
			while (start < end)
				if (queue[start++])
					return (0);
		}
		else
		{
			queue[end++] = node->left;
			queue[end++] = node->right;
		}
	}
	return (1);
}

/**
 * bst_inorder_max - helper function to traverse a bst using in-order traversal
 *				and determine if it is indeed a max heap
 * @tree: pointer to root node of the tree to traverse
 * @prev: pointer to the node we will use to recursively check against
 * Return: 1 if Max Heap, 0 if not
 */
int bst_inorder_max(const binary_tree_t *tree, const binary_tree_t *prev)
{
	/* traverse inorder and check if we're still in the tree */
	if (tree)
	{
		/* check for duplication or unsorted pairs */
		if (prev && tree->n >= prev->n)
			return (0);
		if (tree->right && !tree->left)
			return (0);
		/* recursive call for right subtree */
		return (bst_inorder_max(tree->left, tree) &&
				bst_inorder_max(tree->right, tree));
	}
	return (1);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Heap
 * @tree: root node of tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* start with prev being NULL, i.e. root of tree */
	return (bst_inorder_max(tree, NULL) && heap_is_complete(tree));
}
