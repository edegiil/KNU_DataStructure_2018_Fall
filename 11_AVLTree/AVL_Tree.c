#include "AVL_Tree.h"

T_NODE* rotate_left(T_NODE* root){
    T_NODE* new_root;
    new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    return new_root;
}

T_NODE* rotate_right(T_NODE* root){
    T_NODE* new_root;
    new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    return new_root;
}