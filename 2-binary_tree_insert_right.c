#include "binary_trees.h"
/**
 * binary_tree_insert_right - Inserts a node as the right-child of
 * another node.
 *
 * @parent: Pointer to the node to insert the right-child in.
 * @value: Value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure or if parent
 * is NULL.
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

	if (!newNode)
		return (NULL);

	if (!parent)
		return (NULL);

	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = parent->right;

	if (parent->right)
		parent->right->parent = newNode;

	parent->right = newNode;

	return (newNode);
}
