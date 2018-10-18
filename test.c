#include <stdio.h>

int main() {
    int a[3] = { 1, 3, 5 };

    int b = sizeof(a)/sizeof(int);

    printf("%d\n", b);

    return 0;
}