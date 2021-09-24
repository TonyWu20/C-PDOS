#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <stdio.h>
#include <string.h>

xmlDocPtr getdoc(char *docname);
xmlXPathObjectPtr getNodeSet(xmlDocPtr doc, xmlChar *xpath);

typedef struct{
		char bandName[1];
		int NumPoints;
		xmlXPathObjectPtr *Points;
} BAND;


