#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, x;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    x = rank + 1;
    printf("Process %d: square of %d = %d\n", rank, x, x * x);
    fflush(stdout);

    MPI_Barrier(MPI_COMM_WORLD);   /* wait until all processes reach here */

    if (rank == 0)
        printf("All processes synchronized at the barrier\n");

    MPI_Finalize();
    return 0;
}
