#include "lexer.h"

Lexer* Lexer::instancePtr = nullptr;

Lexer* Lexer::instance(){
    if(!instancePtr){
        instancePtr = new Lexer;
    }

    return instancePtr;
}

