#include "binary_trees.h"

/**
 * bst_remove - removes node from a binary search tree,
 * in-order successor replaces
 * @root: pointer to the root node
 * @value: value to remove
 *
 * Return: pointer to root node of bst
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *rm_node = NULL, *temp = NULL;

	if (root == NULL)
		return (NULL);
	rm_node = bst_search2(root, value);
	if (rm_node == NULL)
		return (NULL);
	if (rm_node->right)
		temp = set_right(&root, rm_node);
	if (rm_node->left && rm_node->right)
	{
		temp->left = rm_node->left;
		rm_node->left->parent = temp;
	}
	else if (rm_node->left)
	{
		rm_node->left->parent = rm_node->parent;
		if (rm_node->parent && (rm_node->left->n < rm_node->parent->n))
			rm_node->parent->left = rm_node->left;
		else if (rm_node->parent)
			rm_node->parent->right = rm_node->left;
		else
			root = rm_node->left;
	}
	else if (rm_node->left == NULL && rm_node->right == NULL)
	{
		if (rm_node->parent && (rm_node->n < rm_node->parent->n))
			rm_node->parent->left = NULL;
		else if (rm_node->parent)
			rm_node->parent->right = NULL;
		else
			root = NULL;
	}
	free(rm_node);
	return (root);
}

/**
 * bst_search2 - finds location of where the value should be inserted
 * @tree: tree to sort in binary search order
 * @value: value to find where should be inserted
 *
 * Return: pointer to location to insert value at
 */
bst_t *bst_search2(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search2(tree->left, value));
	return (bst_search2(tree->right, value));
}

/**
 * set_right - sets right side if node removing has right child
 * @root: double pointer to root node of the tree
 * @rm_node: pointer to node to remove from tree
 *
 * Return: pointer to temp node reclacing removed node
 */
bst_t *set_right(bst_t **root, bst_t *rm_node)
{
	bst_t *temp = NULL;

	temp = rm_node->right;
	while (temp->left)
		temp = temp->left;
	if (temp != rm_node->right)
	{
		temp->right = rm_node->right;
		rm_node->right->parent = temp;
		temp->parent->left = NULL;
	}
	temp->parent = rm_node->parent;
	if (rm_node->parent && (temp->n < rm_node->parent->n))
		rm_node->parent->left = temp;
	else if (rm_node->parent)
		rm_node->parent->right = temp;
	else
		(*root) = temp;
	return (temp);
}
