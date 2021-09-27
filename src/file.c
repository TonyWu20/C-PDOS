#include "C_PDOS.h"
#include <ftw.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <stdio.h>
#include <stdlib.h>

int parseBandCenter(char *docname)
{
    xmlDocPtr doc;
    xmlChar *bands = (xmlChar *)"//SERIES_2D";
    xmlXPathObjectPtr result;
    doc = getdoc(docname);
    result = getNodeSet(doc, bands);
    if (result)
    {
        xmlNodeSetPtr nodeset;
        nodeset = result->nodesetval;
        BAND *bands[nodeset->nodeNr]; /* Array of pointers to BAND struct */
        getBands(nodeset, bands);     /* Load contents to bands */
        bandCenter(bands[2]);
    }
    else
    {
        fprintf(stderr, "Error: No SERIES_2D node is found!\n");
        return 1;
    }
    xmlXPathFreeObject(result);
    xmlFreeDoc(doc);
    /*xmlCleanupParser();*/
    return 0;
}
int visit(const char *path, const struct stat *stat, int flags, struct FTW *ftw)
{
    extern char *paths[];
    extern int i;
    if (flags == FTW_F && strstr(path, ".DS_Store") == NULL &&
        strstr(path, ".xcd") != NULL)
    {
        paths[i++] = strdup(path);
    }
    return 0;
}
