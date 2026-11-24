#include <stdio.h>
#include <omp.h>

int main() {
    int n, i, a[1000], sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < n; i++)
        sum += a[i];

    printf("Sum = %d\n", sum);
    return 0;
}
