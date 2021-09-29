#include "C_PDOS.h"
#include <ftw.h>
#include <libgen.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <stdio.h>
#include <stdlib.h>

int parseBandCenter(PATHOBJ xcd_file)
{
    xmlDocPtr doc;
    xmlChar *bandXPath = (xmlChar *)"//SERIES_2D";
    xmlXPathObjectPtr result;
    doc = getdoc(xcd_file.fullpath);
    result = getNodeSet(doc, bandXPath);
    if (result)
    {
        xmlNodeSetPtr nodeset;
        nodeset = result->nodesetval;
        BAND *bands[nodeset->nodeNr]; /* Array of pointers to BAND struct */
        getBands(nodeset, bands);     /* Load contents to bands */
        xcd_file.dbandCenter = bandCenter(bands[2]);
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
/*int visit(const char *path, const struct stat *stat, int flags, struct FTW
 * *ftw)*/
/*{*/
/*extern char *paths[];*/
/*extern int i;*/
/*if (flags == FTW_F && strstr(path, ".DS_Store") == NULL &&*/
/*strstr(path, ".xcd") != NULL)*/
/*{*/
/*paths[i++] = strdup(path);*/
/*}*/
/*return 0;*/
/*}*/
int visit(const char *path, const struct stat *stat, int flags, struct FTW *ftw)
{
    if (flags == FTW_F && strstr(path, ".DS_Store") == NULL &&
        strstr(path, ".xcd") != NULL)
    {
        extern PATHOBJ *ptr;
        extern int num_files;
        ptr->fullpath = strdup(path);
        ptr->basename = strdup(basename((char *)path));
        ptr->dirname = dirname((char *)path);
        int j = 0;
        char *tok, *saved;
        for (tok = strtok_r(basename((char *)path), "_", &saved); tok;
             tok = strtok_r(NULL, "_", &saved))
        {
            ptr->token[j++] = tok;
        }
        ptr->tokenNum = j;
        asprintf(&ptr->obj, "%s-%s", ptr->token[2], ptr->token[3]);
        ptr++;
        ++num_files;
    }
    return 0;
}
