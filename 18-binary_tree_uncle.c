#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 *
 * @node: A pointer to the node to find the sibling.
 *
 * Return: A pointer to the sibling node, or NULL if node is NULL or has
 * no sibling.
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;

	if (parent->left != NULL && parent->left != node)
		return (parent->left);

	if (parent->right != NULL && parent->right != node)
		return (parent->right);

	return (NULL);
}

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 *
 * @node: A pointer to the node to find the uncle.
 *
 * Return: A pointer to the uncle node, or NULL if node is NULL, parent is
 * NULL, or if the node has no uncle.
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
