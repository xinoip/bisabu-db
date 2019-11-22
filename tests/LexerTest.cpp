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

        std::string longString(10000000,'a');
        v = l->Lexer::processInput(longString, 'a');
        if(v.size() != 10000)
            success = false;
        
        v = l->Lexer::processInput("Burakcan Asa", ' ');
        if(v.size() != 2)
            success = false;
        std::cout << "***************" << std::endl;
        
        v = l->Lexer::processInput("Burakcan Asa", 'e');
        if(v.size() != 0){
            // should enter error message
            success = false;
        }
        std::cout << "***************" << std::endl;
        
        v = l->Lexer::processInput("Öküz Sümük", 'ü');
        //problem with turkish characters
        std::cout << "***************" << std::endl;
        
        v = l->Lexer::processInput("abbc", 'b');
        std::cout << v.size();
        if(v.size() != 2){
            success = false;
            // problem in consecutive chars, it creates 3 substrings
        }

        //////////////////////////////////////
        // PROCESSINPUT FUNCTION TESTS DONE //
        //////////////////////////////////////



        return success;
    }, "LexerTest");
}
