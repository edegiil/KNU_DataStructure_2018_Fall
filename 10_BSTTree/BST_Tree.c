#include "BST_Tree.h"

BST_TREE* create_bst(){
    BST_TREE* new_tree = (BST_TREE*)malloc(sizeof(BST_TREE));

    new_tree->count = 0;
    new_tree->root = NULL;

    return new_tree;
}

bool BST_insert(BST_TREE* tree, int data){
    T_NODE* new_root = add_bst(tree->root, data);

    if(!new_root){
        return false;
    }else{
        tree->root = new_root;
        ++tree->count;
        return true;
    }
}
bool BST_delete(BST_TREE* tree, int data){
    bool success;
    if(!tree || !(tree->root)){
        return false;
    }

    T_NODE* new_root = del_bst(tree->root, data, &success);

    if(!new_root){
        return false;
    }

    if(success){
        tree->root = new_root;
        --tree->count;
        if(tree->count == 0){
            tree->root = NULL;
        }
    }
    return success;
}

T_NODE* add_bst(T_NODE* root, int data){
    if(!root){
        T_NODE* new_node = (T_NODE*)malloc(sizeof(T_NODE));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
    }

    if(root->data < data){
        root->left = add_bst(root->left, data);
        return root;
    }else{
        root->right = add_bst(root->right, data);
        return root;
    }
}

T_NODE* del_bst(T_NODE* root, int data, bool* success){
    if(root->data > data){
        root->right = del_bst(root->right, data, success);
        return root;
    }else if(root->data < data){
        root->left = del_bst(root->left, data, success);
        return root;
    }else{
        T_NODE* deleted_node = root;
        T_NODE* new_root;

        if(!(deleted_node->right)){
            new_root = deleted_node->left;
            free(deleted_node);
            *success = true;
            return new_root;
        }else if(!(deleted_node->left)){
            new_root = deleted_node->right;
            free(deleted_node);
            *success = true;
            return new_root;
        }else{
            T_NODE* search = root->left;
            while(search->right){
                search = search->right;
            }
            root->data = search->data;
            root->left = del_bst(root->left, search->data, success);
            return root;
        }
    }
}


T_NODE* search_bst(T_NODE* node, int data){
    if(node->data < data){
        return search_bst(node->left, data);
    }else if(node->data > data){
        return search_bst(node->right, data);
    }else{
        return node;
    }
};

T_NODE* find_smallest_node(T_NODE* node){
    if(!(node->left)){
        return node;
    }else{
        return find_smallest_node(node->left);
    }
}

T_NODE* find_largest_node(T_NODE* node){
    if(!(node->right)){
        return node;
    }else{
        return find_largest_node(node->right);
    }
}

void traverse_preorder(T_NODE* root){
    if(root){
        printf("%d\n", root->data);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}
void traverse_inorder(T_NODE* root){
    if(root){
        traverse_preorder(root->left);
        printf("%d\n", root->data);
        traverse_preorder(root->right);
    }
}
void traverse_postorder(T_NODE* root){
    if(root){
        traverse_preorder(root->left);
        traverse_preorder(root->right);
        printf("%d\n", root->data);
    }
}

BST_TREE* copy_tree(BST_TREE* tree){
    BST_TREE* new_tree = create_bst();
    new_tree->root = tree->root;
    if(new_tree->root){
        BST_TREE* left_tree = create_bst();
        BST_TREE* right_tree = create_bst();
        left_tree->root = tree->root->left;
        right_tree->root = tree->root->right;
        new_tree->root->right = copy_tree(new_tree)->root;
        new_tree->root->left = copy_tree(new_tree)->root;
    }
    return new_tree;
}