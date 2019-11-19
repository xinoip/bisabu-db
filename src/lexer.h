#ifndef LEXER_H
#define LEXER_H

#include "commandEnum.h"
#include "vector"

class Lexer{
    public:
    static Lexer* instance();

    void processInput();
    void printHistory();
    void addCommand();
    void resetHistory();

    private:
    Lexer(){}
    Lexer(Lexer&){}
    Lexer& operator=(const Lexer&){}

   static Lexer* instancePtr;

    Command lastCommand;
    std::vector<Command> commandHistory;



};


#endif