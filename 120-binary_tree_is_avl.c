#include "binary_trees.h"

/**
 * bst_inorder - helper function to traverse a bst using in-order traversal
 *				and determine if it is indeed a bst
 * @tree: pointer to root node of the tree to traverse
 * @prev: pointer to the node we will use to recursively check against
 * Return: 1 if BST, 0 if not
 */
int bst_inorder(const binary_tree_t *tree, const binary_tree_t **prev)
{
	/* traverse inorder and check if we're still in the tree */
	if (tree)
	{
		/* recursive call for left subtree */
		if (!bst_inorder(tree->left, prev))
			return (0);
		/* check for duplication or unsorted pairs */
		if (*prev && tree->n <= (*prev)->n)
			return (0);
		/* recursive call for right subtree */
		*prev = tree;
		return (bst_inorder(tree->right, prev));
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
	const binary_tree_t *prev = NULL;

	if (!tree)
		return (0);
	/* start with prev being NULL, i.e. root of tree */
	return (bst_inorder(tree, &prev));
}

/**
 * check_balance - Checks if a binary tree is balanced
 * @tree: pointer to the root node of the tree to check
 * @height: pointer to height variable
 * Return: 1 if tree is balanced, and 0 otherwise
 */
int check_balance(const binary_tree_t *tree, int *height)
{
	int left_height = 0, right_height = 0;

	if (!tree)
	{
		*height = 0;
		return (1);
	}

	if (!check_balance(tree->left, &left_height) ||
		!check_balance(tree->right, &right_height))
		return (0);

	*height = MAX(left_height, right_height) + 1;

	if (ABS(left_height - right_height) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);

	if (!check_balance(tree, &height))
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	return (1);
}
