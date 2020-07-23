#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * with level order traversal
 * @tree: pointer to the root node
 *
 * Return: 1 if complete, 0 otherwise or if NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue = NULL, **queue_check = NULL;
	binary_tree_t *temp = NULL;
	int front = 0, rear = 0, i = 0, end = 500, flag = 0;

	if (tree == NULL)
		return (free_queue_return_0(queue));
	queue = malloc(sizeof(binary_tree_t *) * end);
	if (queue == NULL)
		return (free_queue_return_0(queue));
	for (i = 0; i < end; i++)
		queue[i] = NULL;
	queue[front] = (binary_tree_t *)tree;
	temp = queue[front];
	while (temp)
	{
		if (temp->left)
		{
			if (flag)
				return (free_queue_return_0(queue));
			queue[++rear] = temp->left;
		}
		else
			flag = 1;
		if (temp->right)
		{
			if (flag)
				return (free_queue_return_0(queue));
			queue[++rear] = temp->right;
		}
		else
			flag = 1;
		temp = queue[++front];
		if (rear >= (end - 2))
		{
			end *= 2;
			queue_check = realloc(queue, end);
			if (queue_check == NULL)
				return (free_queue_return_0(queue));
			queue = queue_check;
			for (; i < end; i++)
				queue[i] = NULL;
		}
	}
	free(queue);
	return (1);
}

/**
 * free_queue_return_0 - frees the queue and returns 0 for failure
 * @queue: queue to free
 *
 * Return: 0 for incomplete binary tree or failure
 */
int free_queue_return_0(binary_tree_t **queue)
{
	free(queue);
	return (0);
}
