#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void* data_ptr;
	struct node* link;
} STACK_NODE;
typedef struct stack{
	int count;
	STACK_NODE* top;
} STACK;

STACK* create_stack(){
	printf("creating a stack ...\n");
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if(!stack){
		return 0;
	}
	stack->count = 0;
	stack->top = 0;
	return stack;	
}

int push(STACK* stack, void* in){
	printf("pushing a data into stack...\n");
	STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if(!node){
		return 0;
	}
	node->data_ptr = in;
	node->link = stack->top;
	stack->top = node;
	stack->count++;	
}

void* pop(STACK* stack){
	printf("poping a stack...");
	stack->top = stack->top->link;
	stack->count--;
}

int main() {
	STACK* s1 = create_stack();
	printf("stack1's size is %d\n", s1->count);

	int a = 12;
	int b = 23;
	push(s1, &a);
	push(s1, &b);
	printf("stack1's size is %d\n", s1->count);
	
	pop(s1);
	printf("stack1's size is %d\n", s1->count);
	

	return 0;
}
