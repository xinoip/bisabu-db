#ifndef _Lexer_h_
#define _Lexer_h_

#include "CommandEnum.h"
#include <vector>
#include <string>

class Lexer
{
public:
    static Lexer *instance();

    std::vector<std::string> processInput(const std::string &input, const char token);
    std::vector<std::string> processInput(const char *input, const char token);
    
    void printHistory();
    const bool addCommand(const Command c);
    void resetHistory();

private:
    Lexer() {}
    Lexer(Lexer &) {}
    Lexer &operator=(const Lexer &) {}

    static Lexer *instancePtr;

    Command lastCommand;
    std::vector<Command> commandHistory;
};

#endif