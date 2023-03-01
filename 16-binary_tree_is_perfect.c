#include "binary_trees.h"
/**
 *binary_tree_is_perfect - function that checks if a binary tree is perfect
 *@tree: is a pointer to the root node of the tree to check
 *
 *Return: 1 if is perfect (exactly two child), else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_full(tree) == 1 &&
				(binary_tree_size(tree->left) == binary_tree_size(tree->right)))
		return (1);

	return (0);
}
/**
 *binary_tree_is_full - function that checks if a binary tree is full
 *@tree: is a pointer to the root node of the tree to check
 *Return: 1 if is full, else 0. When tree is NULL return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}
/**
 *binary_tree_size - function that measures the size of a binary tree
 *@tree: is a pointer to the root node of the tree to measure the size
 *Return: size of binary tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}
