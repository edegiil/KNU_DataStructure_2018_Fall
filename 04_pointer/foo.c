#include <stdio.h>

int main() {
	int a, b;
	a = 100;
	b = 200;

	printf("Variable a: %d at address %p\n", a, &a);
	printf("Variable b: %d at address %p\n", b, &b);

	int* a_addr;
	a_addr = &a;

	printf("data at address %p is %d\n", &a, *a_addr);	

	*a_addr = 300;
	printf("data at address %p is %d\n", &a, *a_addr);	

	return 0;
}
