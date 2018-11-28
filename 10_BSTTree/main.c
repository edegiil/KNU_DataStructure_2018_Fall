#include "BST_Tree.h"

int main(){
	BST_TREE* tree = create_bst();

	BST_insert(tree, 5);
	BST_insert(tree, 2);
	BST_insert(tree, 4);
	BST_insert(tree, 7);
	BST_insert(tree, 1);
	BST_insert(tree, 8);
	BST_insert(tree, 9);
	BST_insert(tree, 3);
	BST_insert(tree, 15);
	BST_insert(tree, 6);

	traverse_preorder(tree->root);

	BST_TREE* new_tree = copy_tree(tree);

	traverse_preorder(new_tree->root);

	return 0;
}