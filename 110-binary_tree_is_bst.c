#include "binary_trees.h"
#include <stdio.h>
/**
 * bst_inorder - helper function to traverse a bst using in-order traversal
 *				and determine if it is indeed a bst
 * @tree: pointer to root node of the tree to traverse
 * Return: 1 if BST, 0 if not
 */
int bst_inorder(const binary_tree_t *tree)
{
	static binary_tree_t *prev;

	/* traverse inorder and check if we're still in the tree */
	if (tree)
	{
		/* recursive call for left subtree */
		if (!bst_inorder(tree->left))
			return (0);
		/* check for duplication or unsorted pairs */
		if ((prev && tree->n <= prev->n))
			return (0);
		if ((tree->left && tree->n <= tree->left->n) ||
				(tree->right &&	tree->n >= tree->right->n))
			return (0);
		/* recursive call for right subtree */
		prev = (binary_tree_t *)tree;
		return (bst_inorder(tree->right));
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: root node of tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* start with prev being NULL, i.e. root of tree */
	return (bst_inorder(tree));
}
