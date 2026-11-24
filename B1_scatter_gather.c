#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, i, x, a[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
        for (i = 0; i < size; i++) a[i] = i + 1;

    MPI_Scatter(a, 1, MPI_INT, &x, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d got %d\n", rank, x);

    x = x * x;
    MPI_Gather(&x, 1, MPI_INT, a, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Gathered: ");
        for (i = 0; i < size; i++) printf("%d ", a[i]);
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}
