#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int front = 0, rear = 0, NullChild = 0;
	binary_tree_t **queue, *current;

	if (tree == NULL)
		return (0);
	/* Create a queue to store the nodes to be processed */
	queue = malloc(sizeof(binary_tree_t *) * 1000);
	if (queue == NULL)
		return (0);
	/* Enqueue the root node to start the traversal */
	queue[rear] = (binary_tree_t *)tree;
	rear++;
	while (front < rear)
	{
		/* Dequeue the current node */
		current = queue[front];
		front++;
		/* Check for NULL children in the tree */
		if (current == NULL)
			NullChild = 1;
		else
		{
			/* If we have seen a NULL child, the tree is not complete */
			if (NullChild)
			{
				free(queue);
				return (0);
			}
			/* Enqueue the left child */
			queue[rear] = current->left;
			rear++;
			/* Enqueue the right child */
			queue[rear] = current->right;
			rear++;
		}
	}

	free(queue);
	/* If we reach this point, the tree is complete */
	return (1);
}
