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
    void processInputHistory(const char token);
    
    bool pushInput(const std::string &input);
    bool pushInput(const char *input);

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

    std::string convertCharPtr(const char* input);
    std::vector<std::string> inputHistory;
};

#endif