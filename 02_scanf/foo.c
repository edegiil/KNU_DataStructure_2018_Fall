#include <stdio.h>
#include "increment.h"

int main() {
	int a, b;

	a = 12121;
	printf("a is %d\n", a);

	a = increment(a);
	printf("a incremented is %d\n", a);

	printf("Enter b, a will be replaced to b\n");
	scanf("%d", &b);
	printf("a was %d and b is %d\n", a, b);
	a = increment(b);
	printf("a is now %d\n", a);

	return 0;
}
