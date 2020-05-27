set(SRC_LIB_NAME src)
add_library(${SRC_LIB_NAME})
target_sources(${SRC_LIB_NAME} PRIVATE XMLExporter.cpp StoreEvent.cpp Store.cpp Product.cpp Price.cpp Order.cpp)
target_include_directories(${SRC_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

