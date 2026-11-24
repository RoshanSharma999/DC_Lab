#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, x, y;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    x = rank;

    /* Process 0 sends first, process 1 receives first -> no deadlock */
    if (rank == 0) {
        MPI_Send(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&y, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } else {
        MPI_Recv(&y, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    printf("Process %d received %d\n", rank, y);
    MPI_Finalize();
    return 0;
}
