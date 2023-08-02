#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child in
 * a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count the nodes.
 *
 * Return: The number of nodes with at least one child, or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_count, right_count, has_child;

	has_child = (tree->left != NULL) || (tree->right != NULL);
	left_count = binary_tree_nodes(tree->left);
	right_count = binary_tree_nodes(tree->right);

	return (left_count + right_count + has_child);
}
