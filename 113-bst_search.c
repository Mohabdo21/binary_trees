#include "binary_trees.h"
/**
 * bst_search - searches for a value in a BST
 * @tree: root node of BST
 * @value: value to search
 * Return: pointer to node containing n == value & NULL otherwise
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else if (value > tree->n)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);

}
