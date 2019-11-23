#include "Lexer.h"
#include <sstream>
#include <iostream>

//#define TESTINTERNAL //uncomment to compile with test main.

Lexer *Lexer::instancePtr = nullptr;

Lexer *Lexer::instance()
{
    if (!instancePtr)
    {
        instancePtr = new Lexer;
    }

    return instancePtr;
}

std::vector<std::string> Lexer::tokenizeInput(const std::string &input, const char tokenChar)
{
    std::stringstream parser(input);
    std::string token;
    std::vector<std::string> tokens;

    while (getline(parser, token, tokenChar))
    {
        if(token!="")
        tokens.push_back(token);
    }

#ifdef TESTINTERNAL
    for (unsigned i = 0; i < tokens.size(); ++i)
        std::cout << tokens[i] << std::endl;
#endif

    return tokens;
}

std::vector<std::string> Lexer::tokenizeInput(const char *input, const char token)
{

    return tokenizeInput(convertCharPtr(input), token);
}

void Lexer::processInputHistory(const char token)
{

    for (unsigned i = 0; i < inputHistory.size(); ++i)
    {
        tokenizeInput(inputHistory[i], token);
    }

    inputHistory.clear();
}

bool Lexer::pushInput(const std::string &input)
{
    inputHistory.push_back(input);
    return true;
}

bool Lexer::pushInput(const char *input)
{
    inputHistory.push_back(convertCharPtr(input));
    return true; // useless bool for now. maybe we put a limit for input count in future
}

void Lexer::resetHistory()
{
    commandStream.clear();
}

void Lexer::printHistory()
{

    if (commandStream.empty())
    {
        std::cout << "Command stream is empty\n";
        return;
    }

    for (unsigned i = 0; i < commandStream.size(); ++i)
    {
        std::cout << "Command " << i + 1 << ":";
        switch (commandStream[i])
        {
        case Command::SEL:
            std::cout << "SELECT";
            break;

        case Command::INS:
            std::cout << "INSERT";
            break;

        case Command::UPD:
            std::cout << "UPDATE";
            break;

        case Command::DEL:
            std::cout << "DELETE";
            break;
        }
        std::cout << std::endl;
    }
}

bool Lexer::addCommand(const Command c)
{
    commandStream.push_back(c);
    return true;
}

std::string Lexer::convertCharPtr(const char *input)
{
    std::string temp = "";

    for (int i = 0; input[i] != 0; ++i)
    {
        temp += input[i];
    }
    temp += '\0';

    return temp;
}

#ifdef TESTINTERNAL

int main()
{

    Lexer::instance()->tokenizeInput("Abdullah", 'u');

    Lexer::instance()->addCommand(Command::DEL);
    Lexer::instance()->addCommand(Command::DEL);
    Lexer::instance()->addCommand(Command::SEL);
    Lexer::instance()->addCommand(Command::INS);
    Lexer::instance()->addCommand(Command::DEL);
    Lexer::instance()->addCommand(Command::UPD);

    Lexer::instance()->printHistory();

    Lexer::instance()->resetHistory();

    Lexer::instance()->printHistory();
}

#endif