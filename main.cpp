#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A 100
#define B 100
#define P 100

int main(int argc, char *argv[])
{
    int tid, nthreads, i, j, k;
    double a[A][P], p[P][1], r[A][1];

    //parallel region creation
    #pragma omp parallel shared(a, p, nthreads) private(tid, i)
    {
        tid = omp_get_thread_num();

        //Loop work-sharing construct - distribute rows of matrix
        #pragma omp for
        for (i=0; i < A; i++)
            for (j=0; j < B; j++)
            a[i][j]=i+j;

        //Update and display of running total must be serialized
        #pragma omp for
        for(i=0; i < P; i++)
            p[i][0]=i;

        #pragma omp for
        for (i=0; i < A; i++)
                r[i][0] = 0;

        printf("Multiplication: \n");
        #pragma omp for
        for(i=0; i<A; i++)
        {
            printf("Thread %d did row %d\n", tid, i);
            for(j=0; j<P; j++)
            {
                r[i][0] += a[i][j] * p[j][0];
            }
        }


    }
    return 0;

}
