#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 *
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	/* Store the right child of the root */
	new_root = tree->right;

	/* Update the right child of the root */
	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;

	/* Update the parent pointers */
	new_root->parent = tree->parent;
	tree->parent = new_root;

	/* Update the left child of the new root */
	new_root->left = tree;

	return (new_root);
}
