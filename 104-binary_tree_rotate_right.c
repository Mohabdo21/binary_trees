#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree || !tree->left)
		return (tree);

	/* Pivot on the left child of the tree */
	pivot = tree->left;

	tree->left = pivot->right;

	if (pivot->right != NULL)
		pivot->right->parent = tree;

	pivot->right = tree;

	pivot->parent = tree->parent;
	tree->parent = pivot;

	return (pivot);
}

