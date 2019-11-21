#include "TestDictionary.h"
#include "TestControllers/Test.h"

#include "../src/Lexer.h"

#include <string>
#include <vector>

Test LexerTest()
{
    return Test([]() {
        std::vector<std::string> v;
        Lexer *l = Lexer::instance();
        
        bool success = true;

        if(l == NULL)
            return false;

        v = l->Lexer::processInput("Burakcan Asa", ' ');
        if(v.size() != 2)
            success = false;    
        return success;
    }, "LexerTest");
}
