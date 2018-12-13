#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int last;
    int size;
    int* array;
    int max_size;
}HEAP;

HEAP* create_heap(int max);
bool reheap_up(HEAP* heap, int node);
bool reheap_down(HEAP* heap, int root, int last);
bool insert_heap(HEAP* heap, int data);

void display_heap(HEAP* heap);