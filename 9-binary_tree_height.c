#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height;

	if (tree == NULL)
		return (0);

	height = height_helper(tree);
	return (height - 1);
}

/**
 * height_helper - the heavy lifter
 * @tree: tree to measure
 *
 * Return: height, root inclusive
 */
size_t height_helper(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = (1 + height_helper(tree->left));
	right = (1 + height_helper(tree->right));

	if (left > right)
		return (left);

	return (right);
}
