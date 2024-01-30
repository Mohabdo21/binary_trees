#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to root node of the tree to measure its height
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;
	if (!tree)
		return (0);
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	return (left_height > right_height ? left_height : right_height);
}
/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or if the tree is not perfect, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_h = 0, right_h = 0;

	if (!tree)
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	if (left_h == right_h)
	{
		if (
			binary_tree_is_perfect(tree->left)
			&&
			binary_tree_is_perfect(tree->right)
			)
			return (1);
	}

	return (0);
}

