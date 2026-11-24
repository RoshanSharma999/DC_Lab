#include <stdio.h>
#include <omp.h>

int isPrime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int main() {
    int n, i, count = 0;
    double t;
    printf("Enter n: ");
    scanf("%d", &n);

    t = omp_get_wtime();
    for (i = 1; i <= n; i++)
        count += isPrime(i);
    printf("Serial  : %d primes  time = %f\n", count, omp_get_wtime() - t);

    count = 0;
    t = omp_get_wtime();
    #pragma omp parallel for reduction(+:count)
    for (i = 1; i <= n; i++)
        count += isPrime(i);
    printf("Parallel: %d primes  time = %f\n", count, omp_get_wtime() - t);
    return 0;
}
