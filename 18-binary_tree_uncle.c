#include "binary_trees.h"
/**
 *binary_tree_uncle - function that finds the uncle of a node
 *@node: is a pointer to the node to find the uncle
 *Return: pointer to uncle or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;
	binary_tree_t *grand_parent;

	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	if (node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == NULL || node->parent->parent->right == NULL)
		return (NULL);

	parent = node->parent;
	grand_parent = node->parent->parent;

	if (grand_parent->left->n == parent->n)
		return (grand_parent->right);
	return (grand_parent->left);
}
