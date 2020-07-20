#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTS AND DEFINITIONS */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s bst_t;

typedef struct binary_tree_s avl_t;

typedef struct binary_tree_s heap_t;

/* FUNCTION PROTOTYPES */
/* provided print function prototypes */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s);
static size_t _height(const binary_tree_t *tree);
void binary_tree_print(const binary_tree_t *tree);

/* function to insert new node (0) */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
/* function to insert new node as left child (1) */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/* function to insert new node as right child (2) */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/* function to remove node (3) */
void binary_tree_delete(binary_tree_t *tree);
/* function to determine if the given node is a leaf (4) */
int binary_tree_is_leaf(const binary_tree_t *node);
/* function to determine if the node is the root (5) */
int binary_tree_is_root(const binary_tree_t *node);
/* function to traverse tree using pre-order; run function at each node (6)*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/* function to traverse tree using in-order; run function at each node (7)*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/* function to traverse tree using post-order; run function at each node (8)*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
/* function to find tree's height, starting from given node (9)*/
size_t binary_tree_height(const binary_tree_t *tree);
/* funciton to find tree's depth at current node (10)*/
size_t binary_tree_depth(const binary_tree_t *tree);
/* function to measure the size of the tree, starting from given node (11)*/
size_t binary_tree_size(const binary_tree_t *tree);
/* function to count the number of leaves in the tree (12)*/
size_t binary_tree_leaves(const binary_tree_t *tree);
/* function to count the number of nodes with at least 1 child in tree (13)*/
size_t binary_tree_nodes(const binary_tree_t *tree);
/* function to measure the balance factor of a binary tree (14)*/
int binary_tree_balance(const binary_tree_t *tree);
/* function to determine if the binary tree is full (15) */
int binary_tree_is_full(const binary_tree_t *tree);
/* function to determine if the binary tree is perfect (16) */
int binary_tree_is_perfect(const binary_tree_t *tree);
/* function to find the sibling of a given node (17)*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
/* function to find the aunt/uncle of a given node (18)*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

#endif
