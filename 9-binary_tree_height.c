#include "binary_trees.h"

/**
 *binary_tree_height -measures height of tree
 *@tree: pointer to the root node
 *Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_r;
	size_t height_l;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
