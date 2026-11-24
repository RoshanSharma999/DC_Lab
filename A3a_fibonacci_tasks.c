#include <stdio.h>
#include <omp.h>

int fib(int n) {
    int x, y;
    if (n < 2) return n;
    #pragma omp task shared(x)
    x = fib(n - 1);
    #pragma omp task shared(y)
    y = fib(n - 2);
    #pragma omp taskwait
    return x + y;
}

int main() {
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);

    #pragma omp parallel
    #pragma omp single
    for (i = 0; i < n; i++)
        printf("%d ", fib(i));

    printf("\n");
    return 0;
}
