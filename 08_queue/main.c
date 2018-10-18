#include <stdio.h>
#include <stdlib.h>
#include "ADT_queue.h"

int main() {	
    QUEUE* queue2 = create_queue();
    QUEUE* queue1 = create_queue();
    
    int data_a[8] = {1, 3, 5, 7, 9, 11, 13, 15};
    int data_b[8] = {2, 4, 6, 8, 10, 12, 14, 16};

    printf("merging queue start...\n");
    for(int i = 0; i < sizeof(data_a)/sizeof(int); i++){
        enqueue(queue1, &data_a[i]);
        enqueue(queue2, &data_b[i]);
    }

    QUEUE* merged_queue = create_queue();

    int length = queue1 -> count;
    for(int i = 0; i < length; i++){
        enqueue(merged_queue, dequeue(queue1));
        enqueue(merged_queue, dequeue(queue2));
    }
    printf("merge complete!\n");

    check_queue(merged_queue);

    return 0;
}
