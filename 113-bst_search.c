#include "binary_trees.h"

/**
 * bst_search - finds location of where the value should be inserted
 * @tree: tree to sort in binary search order
 * @value: value to find where should be inserted
 *
 * Return: pointer to location to insert value at
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	/* Base case 1: returns NULL if value is not found */
	if (tree == NULL)
		return (NULL);
	/* Base case 2: returns current node if it equals the value */
	if (tree->n == value)
		return ((bst_t *)tree);

/*
 * Deleted first part of condition, Base case NULL check handles
 * if the tree argument is NULL
 * if the value is less than, keep calling left
 * compare to current node, call left if need to move down "less than"/left
 */
	if (value < tree->n)
		return (bst_search(tree->left, value));
/*
 * See above for deleted condition
 * if value is more than, keep calling right
 * compare to current node, call right if need to move down "more than"/right
 */
	return (bst_search(tree->right, value));
}
