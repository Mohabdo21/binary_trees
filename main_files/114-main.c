#include <stdlib.h>
#include <stdio.h>
#include "../binary_trees.h"

/**
 * print_fam - used for debugging
 */
void print_fam(bst_t *node)
{
	if (!node)
		return;

	printf("-------------------\n");
	printf("Node: %i\n", node->n);
	if (node->parent)
		printf("Parent: %i\n", node->parent->n);
	if (node->left)
		printf("Left: %i\n", node->left->n);
	if (node->right)
		printf("Right: %i\n", node->right->n);
	printf("-------------------\n");

}
/**
 * bst_inorder_fam - used for debugging
 */
void bst_inorder_fam(binary_tree_t *tree, void (*func)(bst_t *))
{
	if (!tree || !func)
		return;
	if (tree->left)
		bst_inorder_fam(tree->left, func);
	func(tree);
	if (tree->right)
		bst_inorder_fam(tree->right, func);

}
/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	bst_t *tree;
	int array[] = {
		79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
		20, 22, 98, 1, 62, 95
	};
	size_t n = sizeof(array) / sizeof(array[0]);

	tree = array_to_bst(array, n);
	if (!tree)
		return (1);
	binary_tree_print(tree);

	tree = bst_remove(tree, 79);
	printf("Removed 79...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 21);
	printf("Removed 21...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 68);
	printf("Removed 68...\n");
	binary_tree_print(tree);
	binary_tree_delete(tree);
	return (0);
}
