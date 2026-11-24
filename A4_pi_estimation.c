#include <stdio.h>
#include <omp.h>

int main() {
    int n, k;
    double sum = 0, factor = 1, t;
    printf("Enter n: ");
    scanf("%d", &n);

    t = omp_get_wtime();
    for (k = 0; k < n; k++) {
        sum += factor / (2.0 * k + 1);
        factor = -factor;                 /* depends on previous iteration */
    }
    printf("Serial   pi = %f  time = %f\n", 4 * sum, omp_get_wtime() - t);

    sum = 0;
    t = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum) private(factor)
    for (k = 0; k < n; k++) {
        factor = (k % 2 == 0) ? 1 : -1;   /* depends only on k */
        sum += factor / (2.0 * k + 1);
    }
    printf("Parallel pi = %f  time = %f\n", 4 * sum, omp_get_wtime() - t);
    return 0;
}
