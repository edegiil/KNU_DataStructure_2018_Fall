#include "ADT_linked_list.h"

NODE* create_node(void* data){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if(!node){
        return NULL;
    }
    node->data_ptr = data;
    node->next = NULL;

    return node;
}

LIST* create_list(){
    LIST* list = (LIST*)malloc(sizeof(LIST));
    if(!list) {
        return NULL;
    }
    list->count = 0;
    list->front = NULL;
    list->rear = NULL;
    list->pos = NULL;

    return list;
}

bool node_insertion(LIST* list, unsigned int index, void* data){
    if(index > list->count && !list){
        return false;
    }

    NODE* node = create_node(data);
    if(list->count == 0){
        list->front = node;
        list->rear = node;
        node->next = NULL;
        list->count++;

        return true;
    }

    int iteration = 0;
    if(index != 0){
        list->pos = list->front;
        while(iteration != index){
            list->pos = list->pos->next;
            iteration++;
        }
        if(index != list->count){
            node->next = list->pos->next;
            list->pos->next = node;    
        }else{
            list->pos->next = node;
            list->rear = node;
        }
    }else{
        node->next = list->front;
        list->front = node;
    }
    
    list->count++;
    return true;
}

void* node_deletion(LIST* list, int index){
    if(!list && index > list->count - 1 && list->count == 0){
        return 0;
    }
    NODE* temp;

    if(list->count != 1){
        unsigned int iteration = 0;
        list->pos = list->front;
        NODE* pre = NULL;
        while(iteration != index - 1){
            pre = list->pos;
            list->pos = list->pos->next;
            iteration++;
        }
        if(index == 0){
            temp = list->front;
            free(list->front);
            list->front = list->front->next;
        }else if(index == list->count - 1){
            temp = list->rear;
            free(list->rear);
            list->rear = pre;
        }else{
            temp = list->pos;
            pre->next = list->pos->next;
            free(list->pos);
        }
    }else{
        temp = list->pos;
        list->front = NULL;
        list->rear = NULL;
        list->pos = NULL;
        list->count = 0;
    }

    void* data = temp->data_ptr;

    list->count--;
    return data;
}

int check_list(LIST* list){
    int length = list->count;
    int data;
    list->pos = list->front;
    for(int i = 0; i < length; i++){
        data = *(int*)list->pos->data_ptr;
        list->pos = list->pos->next;
        printf("%d ", data);
    }
    printf("\n");
}