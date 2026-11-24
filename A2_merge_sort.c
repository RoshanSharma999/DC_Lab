#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int a[1000000], b[1000000], temp[1000000];

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = temp[i];
}

void sort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        sort(a, l, m);
        sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void psort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            sort(a, l, m);
            #pragma omp section
            sort(a, m + 1, r);
        }
        merge(a, l, m, r);
    }
}

int main() {
    int n, i;
    double t;
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) a[i] = b[i] = rand();

    t = omp_get_wtime();
    sort(a, 0, n - 1);
    printf("Sequential time: %f\n", omp_get_wtime() - t);

    t = omp_get_wtime();
    psort(b, 0, n - 1);
    printf("Parallel time  : %f\n", omp_get_wtime() - t);
    return 0;
}
