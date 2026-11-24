#include <stdio.h>
#include <omp.h>

int main() {
    int n, i, a[1000], largest;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    largest = a[0];
    #pragma omp parallel for reduction(max:largest)
    for (i = 0; i < n; i++)
        if (a[i] > largest) largest = a[i];

    printf("Maximum = %d\n", largest);
    return 0;
}
