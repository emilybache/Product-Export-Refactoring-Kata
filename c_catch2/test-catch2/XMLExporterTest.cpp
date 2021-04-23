#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

extern "C"
{
#include "LinkedList.h"
#include "SampleModelObjects.h"
#include "XMLExporter.h"

}


TEST_CASE ("XMLExporter") {
    make_sample_model_objects();

    SECTION("sample section") {
        REQUIRE(true == false);
    }
}




