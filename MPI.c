#include <stdio.h>
#include "mpi.h"
main(int argc, char** argv)
 {
int my_rank, numbertoreceive, numbertosend=77;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
 if (my_rank==0){
 MPI_Recv( &numbertoreceive, 1, MPI_INT, MPI_ANY_SOURCE,
MPI_ANY_TAG, MPI_COMM_WORLD, &status);
 printf("Number received is: %d\n", numbertoreceive);
 }
 else if(my_rank == 1)
 MPI_Send( &numbertosend, 1, MPI_INT, 0, 10, MPI_COMM_WORLD);
 MPI_Finalize();
 }