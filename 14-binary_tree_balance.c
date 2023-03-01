#include "binary_trees.h"
/**
 *binary_tree_balance - measures the balance factor of a binary tree
 *@tree: is a pointer to the root node of the tree
 *
 *Return: if tree is NULL return 0, else return balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 *binary_tree_height -measures height of tree
 *@tree: pointer to the root node
 *Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_r = 0;
	size_t height_l = 0;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return (height_l > height_r ? height_l : height_r);
}
