#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, x = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) x = 50;
    MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d has value %d\n", rank, x);

    MPI_Finalize();
    return 0;
}
