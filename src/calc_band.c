#include "/opt/homebrew/include/omp.h"
#include "C_PDOS.h"
#include <stdio.h>

double bandCenter(BAND *band)
{
    int NumPoints = band->NumPoints;
    /* Trapedoizal method to calculate pede and pde */
    double pedeI, pdeI, bandCenter;
    pedeI = pdeI = 0.0;

#pragma omp parallel for reduction(+ : pedeI, pdeI)
    for (int i = 0; i < NumPoints - 1; i++)
    {
        pedeI += (band->points[i + 1].e - band->points[i].e) *
                 (band->points[i].edos + band->points[i + 1].edos);
        pdeI += (band->points[i + 1].e - band->points[i].e) *
                (band->points[i].dos + band->points[i + 1].dos);
    }

    bandCenter = pedeI / pdeI;

    return bandCenter;
}
