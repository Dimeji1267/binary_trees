#include "binary_trees.h"
/**
 *binary_tree_sibling - function that finds the sibling of a node
 *@node: is a pointer to the node to find the sibling
 *
 *Return: NULL if not exist node and node->parent
 *else pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL)
		return (NULL);

	if (node->parent == NULL)
		return (NULL);

	parent = node->parent;

	if (parent->left && parent->right)
	{
		if (parent->left->n == node->n)
			return (parent->right);
		return (parent->left);
	}
	return (NULL);
}
