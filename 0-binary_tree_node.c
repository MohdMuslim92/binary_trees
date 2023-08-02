#include "binary_trees.h"
/**
 * binary_tree_node - Creates a new binary tree node with the given value and
 *					attaches it to the specified parent node
 *
 * @parent: Pointer to the parent node of the new node.
 * @value: Value to be stored in the new node.
 * Return:
 * - A pointer to the newly created node if successful.
 * - NULL if memory allocation fails, indicating failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}
