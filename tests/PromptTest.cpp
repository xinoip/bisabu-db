#include "TestDictionary.h"
#include "TestControllers/Test.h"
#include "../src/Prompt.h"
#include "../src/Lexer.h"

bool testFunc(Prompt *p, unsigned int l, std::string message)
{
    std::string str;

    std::cout << "***************" << std::endl;
    std::cout << message;
    p->getInput();
    
    str = p->getLastInput();
    
    if (str.length() != l)
    {
        return false;
    }

    std::cout << "***************" << std::endl;

    return true;
}

bool promptTest()
{
    Prompt *p = Prompt::instance();
    bool success = true;

    if (p == nullptr)
    {
        return false;
    }
    
    //First test "test" for checking input with only one whitespace
    if (!testFunc(p,4,"type \"test\" \n"))
    {
        success = false;
        std::cout << "First prompt test failed" << std::endl;
    }
    else
    {
        std::cout << "First prompt test passed" << std::endl;
    }
    

    //Second test "test     " for checking input with multiple whitespaces

    if (!testFunc(p,4,"type \"test     \" \n"))
    {
        success = false;
        std::cout << "Second prompt test failed" << std::endl;
    }
    else
    {
        std::cout << "Second prompt test passed" << std::endl;
    }


    //Third test "test string" for checking input with multiple words

    if (!testFunc(p,11,"type \"test string\" \n"))
    {
        success = false;
        std::cout << "Third prompt test failed" << std::endl;
    }
    else
    {
        std::cout << "Third prompt test passed" << std::endl;
    }

    //Fourth test "test. " for checking input with punctuations

    if (!testFunc(p,5,"type \"test. \" \n"))
    {
        success = false;
        std::cout << "Fourth prompt test failed" << std::endl;
    }
    else
    {
        std::cout << "Fourth prompt test passed" << std::endl;
    }

    //Fifth test " " for checking input which is only whitespace

    if (!testFunc(p,0,"type \" \" \n"))
    {
        success = false;
        std::cout << "Fifth prompt test failed" << std::endl;
    }
    else
    {
        std::cout << "Fifth prompt test passed" << std::endl;
    }

    //Sixth test "2   " for checking input with number

    if (!testFunc(p,1,"type \"2   \" \n"))
    {
        success = false;
        std::cout << "Sixth prompt test failed" << std::endl;
    }
    else
    {
        std::cout << "Sixth prompt test passed" << std::endl;
    }

    //Seventh test "TEST" for checking input with uppercase

    if (!testFunc(p,4,"type \"TEST\" \n"))
    {
        success = false;
        std::cout << "Seventh prompt test failed" << std::endl;
    }
    else
    {
        std::cout << "Seventh prompt test passed" << std::endl;
    }

    return success;
}

Test PromptTest()
{
    return Test(promptTest, "PromptTest");
}