#include "C_PDOS.h"
#include <ftw.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define MAXFILES 5000
const char *path;
char *paths[MAXFILES];
int i = 0;

void test(BAND *band);

int main(int argc, char *argv[])
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    char *docpattern;

    if (argc <= 1)
    {
        fprintf(stdout, "Usage: %s <pattern> [-ncores]\n", argv[0]);
        return 1;
    }
    docpattern = argv[1];
    int core_num = (argc >= 3) ? atoi(argv[2]) : 8; /*default 8 */
    if (core_num < 0) /* when core_num is specified by -n */
        core_num = -core_num;
    printf("Running with %d core(s)\n", core_num);

    if ((nftw(argc >= 2 ? docpattern : ".", visit, 5, 0) != 0))
    {
        perror("nftw");
    }

    /* fork processes to complete jobs */
    pid_t pid[8];
    for (int j = 0; j < core_num; j++)
    {
        pid[j] = fork();
        if (pid[j] == 0)
        {
            /* divide the collected paths */
            for (int k = j * i / core_num; k < (j + 1) * i / core_num; k++)
            {
                parseBandCenter(paths[k]);
            }
            printf("Finish %d to %d\n", j * i / core_num,
                   (j + 1) * i / core_num);
            exit(0);
        }
    }
    int status;
    pid_t wpid;
    while ((wpid = wait(&status)) > 0) /* wait child process finish */
    {
        ;
    }
    gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec -
                        start.tv_usec / 1e6; // in seconds

    printf("parseBandCenter program took %f seconds to execute\n", time_taken);

    return 0;
}
