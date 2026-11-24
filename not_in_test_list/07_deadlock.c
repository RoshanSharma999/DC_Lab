#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, x, y;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    x = rank;

    /* Both processes receive first -> both wait forever (deadlock) */
    printf("Process %d waiting...\n", rank);
    fflush(stdout);
    MPI_Recv(&y, 1, MPI_INT, 1 - rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Send(&x, 1, MPI_INT, 1 - rank, 0, MPI_COMM_WORLD);

    printf("Process %d received %d\n", rank, y);   /* never printed */
    MPI_Finalize();
    return 0;
}
