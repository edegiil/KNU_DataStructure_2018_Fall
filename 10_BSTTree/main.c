#include "BST_Tree.h"

int main(){
	BST_TREE* tree = create_bst();

	if(tree){
		printf("sucsex\n");
	}

	if(BST_insert(tree, 2)){
		printf("insertion Sucsex!!!\n");
		printf("Tree count : %d\n", tree->count);
		printf("%d is root\n", (tree->root->data));
	}

	BST_insert(tree, 5);
	BST_delete(tree, 5);
	// BST_insert(tree, 12);
	// BST_insert(tree, 3);
	// BST_insert(tree, 8);
	// BST_insert(tree, 1);
	// BST_insert(tree, 7);

	printf("%d is right\n", (tree->root->right->data));

	return 0;
}