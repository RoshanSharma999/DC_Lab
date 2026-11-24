#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, x, y;
    MPI_Request r1, r2;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    x = rank;

    /* Non-blocking calls return immediately -> no deadlock */
    MPI_Isend(&x, 1, MPI_INT, 1 - rank, 0, MPI_COMM_WORLD, &r1);
    MPI_Irecv(&y, 1, MPI_INT, 1 - rank, 0, MPI_COMM_WORLD, &r2);
    MPI_Wait(&r1, MPI_STATUS_IGNORE);
    MPI_Wait(&r2, MPI_STATUS_IGNORE);

    printf("Process %d received %d\n", rank, y);
    MPI_Finalize();
    return 0;
}
