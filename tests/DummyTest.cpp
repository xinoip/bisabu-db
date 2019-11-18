#include "TestDictionary.h"
#include "TestControllers/Test.h"

#include "../src/Dummy.h"

Test DummyTest()
{
    return Test([]() {
        bool success = false;

        pio::util::Dummy::Log("ABC");
        success = true;

        return success;
    }, "DummyTest");
}
