#include "binary_trees.h"
/**
 * binary_tree_height_a - measures the height of a binary tree
 * @tree: pointer to root node of the tree to measure its height
 * Return: height of tree
 */
size_t binary_tree_height_a(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (!tree)
		return (0);

	left_h = binary_tree_height_a(tree->left);
	right_h = binary_tree_height_a(tree->right);


	return (1 + (left_h > right_h ? left_h : right_h));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor of the tree. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right_h = 0, left_h = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_h = binary_tree_height_a(tree->left);

	if (tree->right)
		right_h = binary_tree_height_a(tree->right);

	return (left_h - right_h);
}
