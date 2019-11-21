#ifndef LEXER_H
#define LEXER_H

#include "commandEnum.h"
#include <vector>
#include <string>

class Lexer
{
public:
    static Lexer *instance();

    std::vector<std::string> processInput(const std::string &input, const char token);
    void printHistory();
    const bool addCommand(const Command c);
    void resetHistory();
    void pushInput(std::string);

private:
    Lexer() {}
    Lexer(Lexer &) {}
    Lexer &operator=(const Lexer &) {}

    static Lexer *instancePtr;

    Command lastCommand;
    std::vector<Command> commandHistory;
};

#endif