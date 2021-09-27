#include "/opt/homebrew/include/omp.h"
#include "C_PDOS.h"
#include <ftw.h>
#include <stdio.h>
#include <sys/time.h>

#define MAXFILES 5000
const char *path;
char *paths[MAXFILES];
int i = 0;

void test(BAND *band);

int main(int argc, char *argv[])
{
    printf("%d\n", omp_get_num_procs());
    printf("%d\n", omp_get_max_threads());
    char *docpattern;
    struct timeval start, end;

    if (argc <= 1)
    {
        fprintf(stdout, "Usage: %s <pattern>\n", argv[0]);
        return 1;
    }
    docpattern = argv[1];
    gettimeofday(&start, NULL);
    if ((nftw(argc >= 2 ? docpattern : ".", visit, 5, 0) != 0))
    {
        perror("nftw");
    }
    gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec -
                        start.tv_usec / 1e6; // in seconds

    printf("nftw program took %f seconds to execute\n", time_taken);
    gettimeofday(&start, NULL);
#pragma omp parallel for
    for (int j = 0; j < i; j++)
    {
        parseBandCenter(paths[j]);
    }
    gettimeofday(&end, NULL);
    time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec -
                 start.tv_usec / 1e6; // in seconds

    printf("parseBandCenter program took %f seconds to execute\n", time_taken);

    return 0;
}

void test(BAND *band)
{
    /*int i;*/
    /*POINT curPoint;*/
    /*printf("%19s %19s %19s\n", "e", "dos", "edos");*/
    /*for (i = 0; i < band->NumPoints; i++)*/
    /*{*/
    /*curPoint = band->points[i];*/
    /*printf("%19.15f %19.15f %19.15f\n", curPoint.e, curPoint.dos,*/
    /*curPoint.edos);*/
    /*}*/
    bandCenter(band);
    /*printf("points: %d, %s band center = %.16lf\n", band->NumPoints,*/
    /*band->bandName, bcenter);*/
}
