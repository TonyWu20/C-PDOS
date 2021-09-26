#include "C_PDOS.h"
#include <stdio.h>

void test(BAND *band);

int main(int argc, char *argv[])
{
    char *docname;
    xmlDocPtr doc;
    xmlChar *bands = (xmlChar *)"//SERIES_2D";
    xmlXPathObjectPtr result;

    if (argc <= 1)
    {
        fprintf(stdout, "Usage: %s <docname>\n", argv[0]);
        return 1;
    }
    docname = argv[1];
    doc = getdoc(docname);
    result = getNodeSet(doc, bands);
    if (result)
    {
        xmlNodeSetPtr nodeset;
        nodeset = result->nodesetval;
        BAND *bands[nodeset->nodeNr]; /* Array of pointers to BAND struct */
        getBands(nodeset, bands);     /* Load contents to bands */
        test(bands[2]);
    }
    else
    {
        fprintf(stderr, "Error: No SERIES_2D node is found!\n");
    }
    xmlXPathFreeObject(result);
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}

void test(BAND *band)
{
    int i;
    POINT curPoint;
    printf("%19s %19s %19s\n", "e", "dos", "edos");
    for (i = 0; i < band->NumPoints; i++)
    {
        curPoint = band->points[i];
        printf("%19.15f %19.15f %19.15f\n", curPoint.e, curPoint.dos,
               curPoint.edos);
    }
    double bcenter;
    bcenter = bandCenter(band);
    printf("%s band center = %.16lf\n", band->bandName, bcenter);
}
