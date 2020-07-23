#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	/* Variable to hold child , becomes the new root*/
	new_root = tree->left;
	/* Sets new_root parent to NULL*/
	new_root->parent = tree->parent;
	tree->parent = new_root;
	tree->left = new_root->right;
	/* NULL check for tree->left*/
	if (tree->left)
		tree->left->parent = tree;
	new_root->right = tree;
	return (tree->parent);
}
