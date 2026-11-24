#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, i;
    char msg[100];
    char *words[] = {"", "Bangalore", "Ramaiah Institute of Technology",
                     "Information Science and Engineering"};
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        for (i = 1; i <= 3; i++) {
            MPI_Recv(msg, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Root received from process %d: %s\n", i, msg);
        }
    } else if (rank <= 3) {
        MPI_Send(words[rank], strlen(words[rank]) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
