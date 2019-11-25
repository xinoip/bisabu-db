#include "TestDictionary.h"
#include "TestControllers/Test.h"

#include "../src/Lexer.h"

#include <string>
#include <vector>

using std::cout;
using std::endl;

Test LexerTest()
{
    return Test([]() {
        // For the tests
        std::vector<std::string> v;
        Lexer *l = Lexer::instance();

        // If all tests are true than succes is true.
        bool success = true;

        // If the pointer is NULL return false.
        if (l == NULL)
            return false;

        std::string longString(10000, 'a');
        v = l->tokenizeInput(longString, 'a');
        if (v.size() != 10000)
        {
            cout << "Long string separation error." << endl;
            success = false;
        }

        // It must return Burakcan and Asa in the string vector.
        v = l->tokenizeInput("Burakcan Asa", ' ');
        if (v.size() != 2)
        {
            cout << "String separation error." << endl;
            success = false;
        }

        // If given char is not in the string then it must return string itself.
        v = l->tokenizeInput("Burakcan Asa", 'e');
        if (v.size() != 1)
        {
            cout << "Error while searching char in string." << endl;
            success = false;
        }
        
        // If user enter a string within consecutive chars like abbc, it must return a and c.
        v = l->tokenizeInput("abbc", 'b');
        if (v.size() != 2)
        {
            cout << "String separation not working in consecutive chars." << endl;
            success = false;
        }

        //////////////////////////////////////
        // PROCESSINPUT FUNCTION TESTS DONE //
        //////////////////////////////////////

        return success;
    },
                "LexerTest");
}
