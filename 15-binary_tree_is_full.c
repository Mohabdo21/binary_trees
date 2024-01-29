#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or if the tree is not full, return 0.
 *         Otherwise, return 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	/* check if the left and right subtrees are full */
	if (tree->left && tree->right)
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);

		/* if either is not full, return 0 */
		if (left == 0 || right == 0)
			return (0);

		/* if they are full, return 1 */
		return (1);
	}
	/* if the current node is a leaf it considered a full tree */
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (0);
}
