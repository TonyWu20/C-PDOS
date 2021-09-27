#include <ftw.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <stdio.h>
#include <string.h>

#define MAXBANDS 4

typedef struct{
		double e;
		double dos;
		double edos;
} POINT;
typedef struct{
		char bandName[1];
		int NumPoints;
		POINT points[];
} BAND;
xmlDocPtr getdoc(char *docname);
xmlXPathObjectPtr getNodeSet(xmlDocPtr doc, xmlChar *xpath);
int getBands(xmlNodeSetPtr nodeset, BAND *bands[]);
double bandCenter(BAND *band);

int visit(const char *path, const struct stat *stat, int flags, struct FTW *ftw);
int parseBandCenter(char *docname);
void test(BAND *band);
