#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    void* data_ptr;
    struct node* next;
} NODE;

typedef struct {
    int count;
    NODE* front;
    NODE* rear;
    NODE* pos;
} LIST;

NODE* create_node();
LIST* create_list();
bool node_insertion(LIST* list, unsigned int index, void* data);
void* node_deletion(LIST* list, unsigned int index);
int check_list();
