#include <setjmp.h> /* used by cmocka */
#include <stdarg.h> /* used by cmocka */
#include <stddef.h> /* used by cmocka */

#include "LinkedList.h"
#include "SampleModelObjects.h"
#include "XMLExporter.h"
#include <approvals_cmocka.h> /* see https://github.com/codecop/ApprovalTests.c */
#include <cmocka.h>           /* see https://cmocka.org/ */
#include <stdlib.h>           /* used by approvals */
#include <string.h>

struct LinkedList *orders;

static int setup_sample_model_objects(void **state)
{
    (void)state; /* unused */
    make_sample_model_objects();
    orders = make_linked_list();
    linked_list_append(&orders, RecentOrder);
    linked_list_append(&orders, OldOrder);
    return 0;
}

static void exportFull(void **state)
{
    (void)state; /* unused */

    const char *xml = xml_export_full(orders);

    verify_xml(xml);
}

static void exportTaxDetails(void **state)
{
    (void)state; /* unused */

    const char *xml = xml_export_tax_details(orders);

    verify_xml(xml);
}

static void exportStore(void **state)
{
    (void)state; /* unused */
    struct Store *store = FlagshipStore;

    const char *xml = xml_export_store(store);

    verify_xml(xml);
}

static void exportHistory(void **state)
{
    (void)state; /* unused */

    const char *xml = xml_export_history(orders);

    char *first_created = strstr(xml, "createdAt");
    first_created += 9 + 1 /* = */ + 1 /* " */;
    memcpy(first_created, "2018-09-20T00:00Z", 17);

    verify_xml(xml);
}

int main(void)
{
    const struct CMUnitTest test_suite[] = {
        cmocka_unit_test(exportFull),       /* */
        cmocka_unit_test(exportTaxDetails), /* */
        cmocka_unit_test(exportStore),      /* */
        cmocka_unit_test(exportHistory),    /* */
    };

    return cmocka_run_group_tests(test_suite, setup_sample_model_objects, NULL);
}
