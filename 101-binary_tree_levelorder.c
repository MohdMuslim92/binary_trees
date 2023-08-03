#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order
 *							traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node.
 *		The value in the node must be passed as a parameter to this function.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	binary_tree_t **queue, *current;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * 1000);
	if (queue == NULL)
		return;


	/* Enqueue the root node to start the traversal */
	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		/* Dequeue the current node */
		current = queue[front];
		front++;

		/* Call the function on the value of the current node */
		func(current->n);

		/* Enqueue the left child if it exists */
		if (current->left != NULL)
		{
			queue[rear] = current->left;
			rear++;
		}

		/* Enqueue the right child if it exists */
		if (current->right != NULL)
		{
			queue[rear] = current->right;
			rear++;
		}
	}

	free(queue);
}
