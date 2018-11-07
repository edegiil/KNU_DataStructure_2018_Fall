#include "BST_Tree.h"

BST_TREE* create_bst(){
	BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));

	if(!tree){
		return NULL;
	}

	tree->root = NULL;
	tree->count = 0;
}

bool BST_insert(BST_TREE* tree, int data){
	T_NODE* new_root;
	new_root = add_bst(tree->root, data);

	if(new_root == NULL){
		return false;
	}else{
		tree->root = new_root;
		tree->count++;
	}
}

bool BST_delete(BST_TREE* tree, int data){
	bool success;
	T_NODE* new_root = del_bst(tree->root, data, &success);
	if(success){
		tree->root = new_root;
		tree->count--;
		if(tree->count == 0){
			tree->root = NULL;
		}
	}
	return success;
}

T_NODE* add_bst(T_NODE* root, int data){
	if(root == NULL){
		T_NODE* newPtr = (T_NODE*)malloc(sizeof(T_NODE));
		newPtr->left = NULL;
		newPtr->right = NULL;
		newPtr->data = data;
		return newPtr;
	}

	if(root->data > data){
		root->left = add_bst(root->left, data);
		return root;
	}else{
		root->right = add_bst(root->right, data);
		return root;
	}
}

T_NODE* del_bst(T_NODE* root, int data, bool* success){
T_NODE* search;

	if(root == NULL){
		*success = success;
		return NULL;
	}

	if(root->data > data){
		root->left = del_bst(root->left, data, success);
		return root;
	}else if(root->data < data){
		root->right = del_bst(root->right, data, success);
		return root;
	}else{
		T_NODE* deleted_node = root;
		T_NODE* new_root;
		if(root->left = NULL){
			new_root = root->right;
			free(deleted_node);
			*success = true;
			return new_root;
		}else{
			if(root->right == NULL){
				new_root = root->left;
				free(deleted_node);
				*success = true;
				return new_root;
			}else{
				search = root->left;
				while(search->right != NULL){
					search = search->right;
				}
				root->data = search->data;
				root->left = del_bst(root->left, search->data, success);
			}
		}
	}
	return NULL;
}