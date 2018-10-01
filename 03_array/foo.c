#include <stdio.h>
#include "increment.h"

int main() {
	int a, b;
	int data[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	float data_f[10] = { 10.5, 20.5, 30.5, 40.5, 50.5, 60.5, 70.5, 80.5, 90.5, 100.5 };

	a = 12121;
	printf("a is %d\n", a);

	a = increment(a);
	printf("a incremented is %d\n", a);

	printf("Enter b, a will be replaced to b\n");
	scanf("%d", &b);
	printf("a was %d and b is %d\n", a, b);
	a = increment(b);
	printf("a is now %d\n", a);

	for ( int i = 1; i < 11; i++ ){
		printf("%dth one of data is %d\n", i, data[i - 1]);
	}

	for ( int i = 1; i < 11; i++ ){
		printf("%dth one of data_f is %f\n", i, data_f[i - 1]);
	}

	printf("3rd one of the array is %d\n", data[2]);

	return 0;
}
