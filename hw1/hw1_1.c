#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* data_ptr;
    struct node* link;
}STACK_NODE;

typedef struct stack {
    int count;
    STACK_NODE* top;
}STACK;

STACK* create_stack(){
    // printf("creating stack...\n");
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    if(!stack){
        return 0;
    }
    stack -> count = 0;
    stack -> top = 0;
    return stack;
}

int push(STACK* stack, void* in){
    STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
    if(!node || !stack){
        return 0;
    }
    node -> data_ptr = in;
    node -> link = stack -> top;
    stack -> top = node;
    stack -> count++;
    // printf("pushing node to stack complete\n");
    return 1;
} //push function

void* pop(STACK* stack){
    if(!stack || stack -> count == 0){
        return 0;
    }
    void* data = stack -> top -> data_ptr;
    stack -> top = stack -> top -> link;
    stack -> count--;
    return data;
} //pop function

int stack_check(STACK* stack) {
    int size = stack->count;
    
    for(int i = 0; i < size; i++){
        printf("%d\n", *(int*)pop(stack));
    }
} // function for stack visualization

int main() {
    STACK* stack1 = create_stack();
    STACK* stack2 = create_stack();

    int a, b, c, d, e;
    a = 0, b = 1, c = 2, d = 3, e = 4;
    push(stack1, &a);
    push(stack1, &b);
    push(stack1, &c);
    push(stack1, &d);
    push(stack1, &e);

    int f, g, h, i, j;
    f = 5, g = 6, h = 7, i = 8, j = 9;
    push(stack2, &f);
    push(stack2, &g);
    push(stack2, &h);
    push(stack2, &i);
    push(stack2, &j);

    printf("stack merging...\n");

    STACK* stack3 = create_stack();

    int stack_size = stack2 -> count;
    for(int i = 0; i < stack_size; i++){
        push(stack3, pop(stack2));    
    }

    STACK* merged_stack = create_stack();
    merged_stack = stack1;

    stack_size = stack3 -> count;
    for(int i = 0; i < stack_size; i++){
        push(merged_stack, pop(stack3));    
    }

    printf("merging complete...!\nmerged stack\n");
    stack_check(merged_stack);
        
    return 0;
}