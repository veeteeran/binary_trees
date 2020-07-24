#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from array of ints
 * @array: pointer to first element of array
 * @size: size of int array
 *
 * Return: pointer to the root node of bst or NULL if failed
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL, *node = NULL;
	size_t i = 0;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		node = bst_insert(&tree, array[i]);
		if (node == NULL)
			return (NULL);
	}
	return (tree);
}
