#include "C_PDOS.h"

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

int main(int argc, char *argv[])
{
    char *docname;
    xmlDocPtr doc;
    xmlChar *bands = (xmlChar *)"//SERIES_2D";
    xmlNodeSetPtr nodeset;
    xmlXPathObjectPtr result;
    int i;
    xmlChar *bandName;
    xmlChar *NumPoints;

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
        nodeset = result->nodesetval;
        int numNode = nodeset->nodeNr;
        BAND bands[numNode];
        for (i = 0; i < numNode; i++)
        {
            bandName = xmlGetProp(nodeset->nodeTab[i], (xmlChar *)"Name");
            sscanf((const char *)bandName, "%s", bands[i].bandName);
            NumPoints = xmlGetProp(nodeset->nodeTab[i], (xmlChar *)"NumPoints");
            bands[i].NumPoints = atoi((const char *)NumPoints);
            printf("Band %s have %d points\n", bands[i].bandName,
                   bands[i].NumPoints);
            xmlFree(bandName);
            xmlFree(NumPoints);
        }
        xmlXPathFreeObject(result);
    }
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}
