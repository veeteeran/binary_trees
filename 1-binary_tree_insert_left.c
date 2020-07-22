#include "binary_trees.h"

/**
 * binary_tree_t *binary_tree_insert_left - inserts a node as the left-child
 * of another node
 * @parent: parent node of node to insert the left-child
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure or NULL parent
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	new_node->left = parent->left;

	if (parent->left)
		parent->left->parent = new_node;

	parent->left = new_node;
	return (new_node);
}
