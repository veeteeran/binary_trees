#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* Variable to hold child , becomes the new root*/
	new_root = tree->right;
	/* Sets new_root parent to NULL*/
	new_root->parent = tree->parent;
	tree->parent = new_root;
	tree->right = new_root->left;
	/* NULL check for tree->right*/
	if (tree->right)
		tree->right->parent = tree;
	new_root->left = tree;
	return (tree->parent);
}
