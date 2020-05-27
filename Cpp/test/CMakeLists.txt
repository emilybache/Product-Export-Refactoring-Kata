set(TEST_NAME ProductExportCatch2ApprovalTests)
set(SOURCE_FILES
        main.cpp
        XMLExporterTest.cpp)
add_executable(${TEST_NAME} ${SOURCE_FILES})

target_link_libraries(${TEST_NAME} lib src)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 11)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})


