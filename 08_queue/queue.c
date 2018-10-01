#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    void* data_ptr;
    struct node* next;
}QUEUE_NODE;

typedef struct queue{
    int count;
    QUEUE_NODE* front;
    QUEUE_NODE* rear;
}QUEUE;

QUEUE* create_queue(){
    QUEUE* queue;
    queue = (QUEUE*)malloc(sizeof(QUEUE));
    if(queue){
        queue -> count = 0;
        queue -> front = 0;
        queue -> rear = 0;
        return queue;
    }else{
        return 0;
    }
}

int enqueue(QUEUE* queue, void* in){
    QUEUE_NODE* node;
    node = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    if(node){
        node -> data_ptr = in;
        node -> next = 0;
        queue -> rear = node;
        if(queue -> count == 0){
            queue -> front = node;
        }else{
            queue -> rear -> next = node;
        }
        queue -> count++;
        queue -> rear = node;
    
        return 1;
    }else{
        return 0;
    }
}

void* dequeue(QUEUE* queue){
    void* data;
    QUEUE_NODE* out = queue -> front;
    if(queue -> count != 1){
        queue -> front = out -> next;
        data = out -> data_ptr;     
    }else{
        queue -> front = 0; 
    }
    free(out);
    queue -> count--;
    return data;
}

int check_queue(QUEUE* queue){
    for(int i = 0; i < sizeof(queue); i++){
        printf("%d ", *(int*)dequeue(queue));
    }
    printf("\n");
}

int main() {
    QUEUE* queue1 = create_queue();
    QUEUE* queue2 = create_queue();
    
    int data_a[8] = {1, 3, 5, 7, 9, 11, 13, 15};
    int data_b[8] = {2, 4, 6, 8, 10, 12, 14, 16};

    for(int i = 0; i < 8; i++){
        printf("check\n");
        enqueue(queue1, &data_a[i]);
        enqueue(queue2, &data_b[i]);
    }

    printf("%d\n", *(int*)(dequeue(queue1)));
    printf("%d\n", *(int*)(dequeue(queue1)));
   
    // check_queue(queue1);

    QUEUE* merged_queue = create_queue();

    for(int i = 0; i < sizeof(queue1); i++){
        // enqueue(merged_queue, dequeue(queue1));
        // enqueue(merged_queue, dequeue(queue2));
    }

    // check_queue(merged_queue);

    return 0;
}