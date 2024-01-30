#include "binary_trees.h"
#include <sys/types.h>

/**
 * inorder_successor - find the inorder_successor of a node
 * @node: pointer to root node of the tree to traverse
 * Return: pointer to the inorder_successor
 */
bst_t *inorder_successor(bst_t *node)
{
	if (!node)
		return (NULL);
	if (node->left)
		return (inorder_successor(node->left));
	return (node);
}
/**
 * bst_remove - removes a node from a BST
 * @root: root node of BST
 * @value: value of node to remove
 * Return: pointer to new root node of the tree after removing the node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else /* we found the element */
	{
		bst_t *successor = NULL;

		if (!root->left && !root->right) /* no children */
		{
			free(root);
			root = NULL;
		}
		else if (!root->left)/* right child */
		{
			successor = root;
			root = root->right;
			free(successor);
			successor = NULL;
		}
		else if (!root->right)/* left child */
		{
			successor = root;
			root = root->left;
			free(successor);
			successor = NULL;
		}
		/* 2 children, find next successor using inorder_successor */
		else
		{
			successor = inorder_successor(root->right);
			root->n = successor->n;
			root->right = bst_remove(root->right, successor->n);
		}
	}
	return (root);
}
