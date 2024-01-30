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
 * delete - delete a node "root" and succeed it by successor
 * @root: root node of tree to delete
 * @successor: successor to the root node
 * Return: address of the successor
 */
bst_t *delete(bst_t *root, bst_t *successor)
{
	successor->parent = root->parent;
	free(root);
	root = NULL;
	return (successor);
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
	/* we found the element */
	else
	{
		/* no children */
		if (!root->left && !root->right)
			free(root),	root = NULL;
		/* right child */
		else if (!root->left)
			root = delete(root, root->right);
		/* left child */
		else if (!root->right)
			root = delete(root, root->left);
		/* 2 children, find next successor using inorder_successor */
		else
		{
			bst_t *successor = NULL;

			successor = inorder_successor(root->right);
			root->n = successor->n;
			/* recursive call to handle the "succession" process */
			root->right = bst_remove(root->right, successor->n);
		}
	}
	return (root);
}
