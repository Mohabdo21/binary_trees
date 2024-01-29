#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to node in the tree to measure its depth
 * Return: height of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: If either node is NULL, or if no common ancestor was found,
 *         return NULL. Otherwise, return a pointer to the lowest common
 *         ancestor node of the two given nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t first_d, second_d;

	if (!first || !second)
		return (NULL);

	first_d = binary_tree_depth(first);
	second_d = binary_tree_depth(second);

	/**
	 * If the first node is deeper than the second node,
	 * move up from the first node
	 */
	while (first_d > second_d)
	{
		first = first->parent;
		first_d--;
	}

	/**
	 * If the second node is deeper than the first node,
	 * move up from the second node
	 */
	while (second_d > first_d)
	{
		second = second->parent;
		second_d--;
	}

	/* Move up from both nodes until you reach a common ancestor */
	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *)first);
}
