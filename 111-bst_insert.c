#include "binary_trees.h"

/**
 * bst_insert - inserts value into binary search tree
 * @tree: double pointer to the root node of the tree
 * @value: value to organize and add into the tree
 *
 * Return: pointer to the node created or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *location = NULL;

	/* if tree reference doesn't exist, return NULL */
	if (tree == NULL)
		return (NULL);

	/* create new_node, check if failed */
	new_node = binary_tree_node((*tree), value);
	if (new_node == NULL)
		return (NULL);

	/* if tree is empty, set new node as tree */
	if ((*tree) == NULL)
	{
		(*tree) = new_node;
		return (new_node);
	}

/*
 * Big changes to location finding function - I was thinking of this backwards.
 * You don't want to change around parents, keep current nodes where they are.
 * You just need to move down to last row:
 * move left if less than current node
 * move right is more than current node
 */
	location = location_finder((*tree), value);
	/* if you found duplicate along your path, free and return NULL */
	if (location->n == value)
	{
		free(new_node);
		return (NULL);
	}

	/* if value < location, need to add value as left child */
	if (new_node->n < location->n)
		location->left = new_node;

	/* if value > location, need to add value as right child */
	if (location->n < new_node->n)
		location->right = new_node;

	/* new_node's parent is always location */
	new_node->parent = location;
	return (new_node);
}

/**
 * location_finder - finds location of where the value should be inserted
 * @tree: tree to sort in binary search order
 * @value: value to find where should be inserted
 *
 * Return: pointer to location to insert value at
 */
bst_t *location_finder(bst_t *tree, int value)
{
	/* if you are a leaf, this is where you want to insert */
	if (tree->left == NULL && tree->right == NULL)
		return (tree);
/*
 * if you have a left child and the value is less than, keep calling left
 * note: big change here is tree->n instead of tree->left->n in if condition
 * compare to current node, call left if need to move down "less than"/left
 */
	if (tree->left && value < tree->n)
		tree = location_finder(tree->left, value);
/*
 * if you have a right child and the value is more than, keep calling right
 * note: big change here is tree->n instead of tree->right->n in if condition
 * compare to current node, call right if need to move down "more than"/right
 */
	if (tree->right && tree->n < value)
		tree = location_finder(tree->right, value);
	/* this catches if duplicate value found */
	return (tree);
}
