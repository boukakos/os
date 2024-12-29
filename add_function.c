#include <stdio.h>

void add(int *a, int *b, int *c, int *result) {
    *result = *a + *b + *c;
}

int main() {
    int x = 5, y = 10, z = 15;
    int result = 0;
    add(&x, &y, &z, &result);
    printf("Sum: %d\n", result);
    return 0;
}
