#include <stdio.h>
#include "increment.h"

int main() {
	int a;

	a = 12121;
	printf("a is %d\n", a);

	a = increment(a);
	printf("a incremented is %d\n", a);

	return 0;
}
