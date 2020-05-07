/***********************************************************************
 * Mu Approvals - micro Approvals for C99.
 * Copyright (c) 2020, Peter Kofler. All rights reserved.
 * BSD licensed.
 */

extern const char* approvals_verify(const char* received,
                                    const char* full_file_name,
                                    const char* test_name,
                                    const char* extension_no_dot);

#define verify_xml(xml, testName)                                                \
    const char* __approved = approvals_verify((xml), __FILE__, testName, "xml"); \
    assert_string_equal(__approved, (xml));
