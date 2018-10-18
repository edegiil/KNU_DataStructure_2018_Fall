#include "ADT_queue.h"

QUEUE* create_queue(){
    printf("creating stack...\n");
    QUEUE* queue;
    queue = (QUEUE*)malloc(sizeof(QUEUE));
    if(!queue){
        return NULL;
    }else{
        queue -> count = 0;
        queue -> front = NULL;
        queue -> rear = NULL;
        return queue;
    }
}

bool enqueue(QUEUE* queue, void* in){
    QUEUE_NODE* node;
    node = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    if(!node){
        return false;
    }
    node -> data_ptr = in;
    node -> next = NULL;
    
    if(queue -> count == 0){
        queue -> front = node;
    }else{
        queue -> rear -> next = node;
    }
    queue -> rear = node;
    queue -> count++;

    return true;
}

void* dequeue(QUEUE* queue){
    QUEUE_NODE* temp = queue -> front;
    void* data = temp -> data_ptr;
    if(queue -> count != 1){
        queue -> front = temp -> next;
    }else{
        queue -> front = NULL;
        queue -> rear = NULL;
    }
    free(temp);
    queue -> count--;
    return data;
}

int check_queue(QUEUE* queue){
    int length = queue -> count;
    for(int i = 0; i < length; i++){
        printf("%d ", *(int*)dequeue(queue));
    }
    printf("\n");
}

