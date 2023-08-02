#include "binary_trees.h"
/**
 * binary_tree_is_leaf - Check if the node is a leaf.
 *
 * @node: the node to be checked
 *
 * Return: 1 if the node is a leaf, 0 if the node is not a leaf
 * or NULL.
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}
