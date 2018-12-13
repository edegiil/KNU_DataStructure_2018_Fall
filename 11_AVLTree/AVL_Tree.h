#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    int balance;
} T_NODE;

typedef struct {
    int count;
    T_NODE* root;
} AVL_TREE;

T_NODE* rotate_left(T_NODE* root);
T_NODE* rotate_right(T_NODE* root);
