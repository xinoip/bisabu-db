#ifndef _Lexer_h_
#define _Lexer_h_

#include "CommandEnum.h"
#include <vector>
#include <string>
#include <map>

class Lexer
{
public:
    static Lexer *instance();

    std::vector<std::string> tokenizeInput(const std::string &input, const char token);
    std::vector<std::string> tokenizeInput(const char *input, const char token);

    void processInputHistory(const char token);

    bool pushInput(const std::string &input);
    bool pushInput(const char *input);

    void printHistory();
    bool addCommand(const Command c);
    void resetHistory();

    // need to implement these
    // process and add the correct command to commandHistory
    // for now if you add successfully just print the name of command
    bool processInput(const std::vector<std::string> &v);

    // just print the name of command from commandHistory
    // after printing pop the command from commandHistory
    // in the future we will call command objects run method
    void processCommands();

private:
    Lexer();
    Lexer(Lexer &);
    Lexer &operator=(const Lexer &);
    //might need destructor

    static Lexer *instancePtr;

    Command lastCommand;
    std::vector<Command> commandStream;

    std::vector<std::string> inputHistory;
    std::map<std::string, Command> tempCommandList;

    //helpers
    std::string convertCharPtr(const char *input) const;
    void printCommand(const Command c) const;
};

#endif