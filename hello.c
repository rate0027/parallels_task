#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
  int n, myid, numprocs, i;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	printf("Hello world %d\n", myid);
	MPI_Finalize();

}
