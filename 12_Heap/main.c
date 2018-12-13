#include "Heap.h"

int main(){
    HEAP* heap = create_heap(10);

    insert_heap(heap, 7);
    insert_heap(heap, 6);
    insert_heap(heap, 11);
    insert_heap(heap, 44);
    insert_heap(heap, 2);
    insert_heap(heap, 13);
    insert_heap(heap, 9);
    insert_heap(heap, 5);

    // for(int i = 0; i <= heap->last; i++){
    //     reheap_down(heap, i, heap->last);
    // }

    // // printf("before\n");
    // // reheap_down(heap, 0, heap->last);
    // // printf("after\n");

    display_heap(heap);

    return 0;
}