#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, x, max, min, sum, prod;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    x = rank + 1;

    MPI_Reduce(&x, &max,  1, MPI_INT, MPI_MAX,  0, MPI_COMM_WORLD);
    MPI_Reduce(&x, &min,  1, MPI_INT, MPI_MIN,  0, MPI_COMM_WORLD);
    MPI_Reduce(&x, &sum,  1, MPI_INT, MPI_SUM,  0, MPI_COMM_WORLD);
    MPI_Reduce(&x, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    if (rank == 0)
        printf("Reduce: max=%d min=%d sum=%d prod=%d\n", max, min, sum, prod);

    MPI_Allreduce(&x, &max,  1, MPI_INT, MPI_MAX,  MPI_COMM_WORLD);
    MPI_Allreduce(&x, &min,  1, MPI_INT, MPI_MIN,  MPI_COMM_WORLD);
    MPI_Allreduce(&x, &sum,  1, MPI_INT, MPI_SUM,  MPI_COMM_WORLD);
    MPI_Allreduce(&x, &prod, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);
    printf("Allreduce (process %d): max=%d min=%d sum=%d prod=%d\n", rank, max, min, sum, prod);

    MPI_Finalize();
    return 0;
}
