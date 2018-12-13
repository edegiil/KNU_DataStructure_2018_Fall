#include "Heap.h"

HEAP* create_heap(int max){
    HEAP* heap = (HEAP*)malloc(sizeof(HEAP));
    heap->last = -1;
    heap->size = 0;
    heap->array = (int*)malloc(sizeof(int)* max);
    heap->max_size = max;
    return heap;
}

bool reheap_up(HEAP* heap, int new_node){
    if(new_node == 0){
        return false;
    }
    int* array = heap->array;
    int parent = *(array + (new_node - 1) / 2);
    if(parent < *(array + new_node)){
        int temp = parent;
        *(array + (new_node - 1)/2) = *(array + new_node);
        *(array + new_node) = temp;
        return reheap_up(heap, new_node/2);
    }
    return true;
}

bool reheap_down(HEAP* heap, int root, int last){
    if(root * 2 + 1 > last){
        return false;
    }

    int* array = heap->array;
    int right = *(array + (root + 1) * 2);
    int left = *(array + root * 2 + 1);

    if(right > left){
        int temp = left;
        *(array + (root * 2 + 1)) = *(array + root);
        *(array + root) = temp;
        return reheap_down(heap, (root * 2 +  1), last);
    }else{
        int temp = right;
        *(array + (root + 1) * 2) = *(array + root);
        *(array + root) = temp;
        return reheap_down(heap, (root + 1) * 2, last);
    }
}

bool insert_heap(HEAP* heap, int data){
    if(heap->size == heap->max_size){
        return false;
    }
    int* array = heap->array;
    heap->last = heap->last + 1;
    heap->size = heap->size + 1;
    *(array + heap->last) = data;
    heap->array = array;

    reheap_up(heap, heap->last);
    return true;
}

void display_heap(HEAP* heap){
    int* array = heap->array;
    for(int i = 0; i <= heap->last; i++){
        printf("%d ", *(array + i));
    }
    printf("\n");
}