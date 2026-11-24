#include <stdio.h>
#include <omp.h>

int main() {
    int n, i, tid[1000];
    printf("Enter number of iterations: ");
    scanf("%d", &n);

    #pragma omp parallel for schedule(static, 2)
    for (i = 0; i < n; i++)
        tid[i] = omp_get_thread_num();

    for (i = 0; i < n; i += 2)
        printf("Thread %d: Iterations %d -- %d\n", tid[i], i, (i + 1 < n) ? i + 1 : i);
    return 0;
}
