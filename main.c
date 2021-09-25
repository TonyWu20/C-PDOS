#include <assert.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlstring.h>
#include <libxml/xmlversion.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <stdio.h>
#include <string.h>

static void usage(const char *name);
static int getSubElm(const char *filename, const xmlChar *xpathExpr);
void print_xpath_nodes(xmlDocPtr doc, xmlNodeSetPtr nodes, FILE *output);
void print_xpath_attrib(xmlDocPtr doc, xmlNodeSetPtr nodes, FILE *output);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Error: wrong number of arguments.\n");
        usage(argv[0]);
        return -1;
    }
    /* Init libxml */
    xmlInitParser();
    LIBXML_TEST_VERSION
    /* Do the main job */
    if (getSubElm(argv[1], BAD_CAST argv[2]) < 0)
    {
        usage(argv[0]);
        return -1;
    }
    /* Shutdown libxml */
    xmlCleanupParser();
    return 0;
}

static int getSubElm(const char *filename, const xmlChar *xpathExpr)
{
    xmlDocPtr doc;
    xmlXPathContextPtr xpathCtx;
    xmlXPathObjectPtr xpathObj;

    assert(filename);
    assert(xpathExpr);

    /* Load XML document */
    doc = xmlParseFile(filename);
    if (doc == NULL)
    {
        fprintf(stderr, "Error: unable to parse file \"%s\"\n", filename);
        return (-1);
    }
    /* Create xpath evaluation context */
    xpathCtx = xmlXPathNewContext(doc);
    if (xpathCtx == NULL)
    {
        fprintf(stderr, "Error: unable to create new XPath context\n");
        xmlFreeDoc(doc);
        return (-1);
    }
    /* Evaluate xpath expression */
    xpathObj = xmlXPathEvalExpression(xpathExpr, xpathCtx);
    if (xpathObj == NULL)
    {
        fprintf(stderr, "Error: unable to evaluate xpath expression \"%s\"\n",
                xpathExpr);
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return (-1);
    }
    /* Print results */
    print_xpath_nodes(doc, xpathObj->nodesetval, stdout);

    /* Cleanup */
    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    xmlFreeDoc(doc);

    return 0;
}

/**
 * print_xpath_nodes:
 * @nodes: the nodes set.
 * @output: the output file handle.
 *
 * Prints the @nodes content to @output.
 */
void print_xpath_nodes(xmlDocPtr doc, xmlNodeSetPtr nodes, FILE *output)
{
    xmlNodePtr cur;
    xmlChar *key;
    int size;
    int i;
    assert(output);
    size = (nodes) ? nodes->nodeNr : 0;
    fprintf(output, "Result (%d nodes):\n", size);
    for (i = 0; i < size; ++i)
    {
        assert(nodes->nodeTab[i]);

        if (nodes->nodeTab[i]->type == XML_NAMESPACE_DECL)
        {
            xmlNsPtr ns;
            ns = (xmlNsPtr)nodes->nodeTab[i];
            cur = (xmlNodePtr)ns->next;
            if (cur->ns)
            {
                fprintf(output, "= namespace \"%s\"=\"%s\" for node %s:%s\n",
                        ns->prefix, ns->href, cur->ns->href, cur->name);
            }
            else
            {
                fprintf(output, "= namespace \"%s\"=\"%s\" for node %s\n",
                        ns->prefix, ns->href, cur->name);
            }
        }
        else if (nodes->nodeTab[i]->type == XML_ELEMENT_NODE)
        {
            cur = nodes->nodeTab[i];
            if (cur->ns)
            {
                fprintf(output, "= element node \"%s:%s\"\n", cur->ns->href,
                        cur->name);
            }
            else
            {
                fprintf(output, "= element node \"%s\"\n", cur->name);
                key = xmlGetProp(cur, (const xmlChar *)"Name");
                fprintf(output, "%s\n", key);
            }
        }
        else
        {
            cur = nodes->nodeTab[i];
            fprintf(output, "= node \"%s\": type %d\n", cur->name, cur->type);
        }
    }
}

static void usage(const char *name)
{
    assert(name);
    fprintf(stderr, "Usage: %s <xml-file> <xpath-expr> \n", name);
}
