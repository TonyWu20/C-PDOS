#include "C_PDOS.h"
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

xmlDocPtr getdoc(char *docname)
{
    xmlDocPtr doc;
    doc = xmlParseFile(docname);
    if (doc == NULL)
    {
        fprintf(stderr, "Document not parsed successfully.\n");
        return NULL;
    }

    return doc;
}

xmlXPathObjectPtr getNodeSet(xmlDocPtr doc, xmlChar *xpath)
{
    xmlXPathContextPtr context;
    xmlXPathObjectPtr result;
    context = xmlXPathNewContext(doc);
    if (context == NULL)
    {
        fprintf(stderr, "Error in xmlXPathNewContext\n");
        return NULL;
    }
    result = xmlXPathEvalExpression(xpath, context);
    xmlXPathFreeContext(context);
    if (result == NULL)
    {
        fprintf(stderr, "Error in xmlXPathEvalExpression\n");
        return NULL;
    }
    if (xmlXPathNodeSetIsEmpty(result->nodesetval))
    {
        xmlXPathFreeObject(result);
        fprintf(stderr, "No result.\n");
        return NULL;
    }
    return result;
}

/** get BAND struct pointers from the XPath parsed result
 * @result: xmlXPathObjectPtr;
 * returns: pointers of BANDS;
 */
int getBands(xmlNodeSetPtr nodeset, BAND *bands[])
{
    int numNode = nodeset->nodeNr; /* Number of nodes in //SERIES_2D */
    xmlNodePtr child;
    xmlChar *bandName;
    int i, j, k;   /* for loop indexing */
    int NumPoints; /* Record number of points in SERIES_2D */
    for (i = 0; i < numNode; i++)
    {
        bandName = xmlGetProp(nodeset->nodeTab[i],
                              (xmlChar *)"Name"); /*get band name */
        NumPoints = atoi((const char *)xmlGetProp(
            nodeset->nodeTab[i],
            (xmlChar *)"NumPoints")); /* get number of points */
        bands[i] =
            malloc(sizeof(POINT) * NumPoints +
                   sizeof(*bands[i])); /* Allocate storage to the points[] */
        /* Save bandName and NumPoints to bands[i] */
        sscanf((const char *)bandName, "%s", bands[i]->bandName);
        bands[i]->NumPoints = NumPoints;

        /* Test */
        printf("Band %s have %d points\n", bands[i]->bandName,
               bands[i]->NumPoints);
        /* Walkthrough children nodes*/
        child = nodeset->nodeTab[i]->children;
        /** The range of j must be NumPoints * 2 since the <POINT_2D> node has
         * no string. The string also counts for 1 child nodes. To proceed to
         * next <POINT_2D XY="...">, we must go two steps further. Directly
         * child->next->next is not available, it will induce segfault.*/
        for (j = 0, k = 0; j <= NumPoints * 2 && child != NULL;
             j++, child = child->next)
        {
            if ((!xmlStrcmp(child->name, (const xmlChar *)"POINT_2D")))
            {
                POINT curPoint; /* for readibility */
                curPoint = bands[i]->points[k];
                sscanf((const char *)xmlGetProp(child, (xmlChar *)"XY"),
                       "%lf,%lf", &curPoint.e, &curPoint.dos);
                curPoint.edos = curPoint.e * curPoint.dos;
                bands[i]->points[k++] = curPoint;
            }
        }
        xmlFree(bandName);
    }
    return i;
}
