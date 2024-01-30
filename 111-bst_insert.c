#include "binary_trees.h"
/**
 * bst_insert - insert value in a BST
 * @tree: double pointer to root node of BST
 * @value: value to store in the node to be inserted
 * Return: pointer to new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL, *parent = (*tree);

	if (!tree || !(*tree))
	{
		node = binary_tree_node(parent, value);
		(*tree) = node;
	}
	else
	{
		while (parent && parent->n != value)
		{
			if (parent->n > value)
				if (parent->left)
					parent = parent->left;
				else
				{
					node = binary_tree_node(parent, value);
					parent->left = node;
				}
			else
				if (parent->right)
					parent = parent->right;
				else
				{
					node = binary_tree_node(parent, value);
					parent->right = node;
				}
		}
	}

	return (node);

}
