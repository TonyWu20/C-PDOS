#include "C_PDOS.h"

double bandCenter(BAND *band)
{
    int NumPoints = band->NumPoints;
    double e[NumPoints], dos[NumPoints], edos[NumPoints];
    int i; /* for loop indexing */
    /* extract each point's e, dos, edos to three arrays */
    for (i = 0; i < NumPoints; i++)
    {
        POINT curPoint = band->points[i];
        e[i] = curPoint.e;
        dos[i] = curPoint.dos;
        edos[i] = curPoint.edos;
    }
    /* Trapedoizal method to calculate pede and pde */
    double pedeI, pdeI, bandCenter;
    pedeI = pdeI = 0.0;
    for (i = 0; i < NumPoints; i++)
    {
        pedeI += (e[i + 1] - e[i]) * (edos[i] + edos[i + 1]);
        pdeI += (e[i + 1] - e[i]) * (dos[i] + dos[i + 1]);
    }
    bandCenter = pedeI / pdeI;

    return bandCenter;
}
