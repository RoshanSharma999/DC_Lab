#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, x;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        x = 100;
        MPI_Send(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent %d to process 1\n", x);
    } else if (rank == 1) {
        MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received %d from process 0\n", x);
    }

    MPI_Finalize();
    return 0;
}
        