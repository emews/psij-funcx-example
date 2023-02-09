#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mpi.h>


void usage (void)
{
    fprintf(stderr,
            "Usage  :   ./mpi_hello <walltime>"
            );
}

int main(int argc, char *argv[])
{
    int  repeat = 1;
    char ch;
    int myrank;
    int nprocs;
    int ticks;
    int type = 1;
    char processor_name[200];
    int namelen;
    int bs = 4; // Default block size
    int stat;
    int walltime;

    if (argc != 2) {
	usage();
	return 0;
    }

    walltime = atoi(argv[1]);

    MPI_Init(&argc, &argv);

    stat = MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    if ( stat != 0 ) error ("MPI_Comm_size returned an error code : %d", stat);

    stat = MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    if ( stat != 0 ) error ("MPI_Comm_rank returned an error code : %d", stat);

    MPI_Get_processor_name(processor_name, &namelen);
    fprintf(stderr, "[Rank:%d] Processor : %s\n", myrank, processor_name);
    fprintf(stdout, "[Rank:%d] Sleeping for %d\n", myrank, walltime);
    sleep(walltime);
    fprintf(stdout, "[Rank:%d] Done sleeping\n", myrank);
    MPI_Finalize();

    return 0;
}
