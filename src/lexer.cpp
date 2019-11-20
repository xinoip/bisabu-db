#include "lexer.h"
#include <sstream>
#include <iostream>

Lexer *Lexer::instancePtr = nullptr;

Lexer *Lexer::instance()
{
    if (!instancePtr)
    {
        instancePtr = new Lexer;
    }

    return instancePtr;
}

std::vector<std::string> Lexer::processInput(const std::string &input, const char tokenChar)
{
    std::stringstream parser(input);
    std::string token;
    std::vector<std::string> tokens;

    while (getline(parser, token, tokenChar))
    {
        tokens.push_back(token);
    }

    for (int i = 0; i < tokens.size(); ++i)
        std::cout << tokens[i] << std::endl;

    return tokens;
}

void Lexer::resetHistory()
{
    commandHistory.clear();
}

void Lexer::printHistory()
{

    if(commandHistory.empty()){
         std::cout << "History is empty\n";
         return;
    }

    for (int i = 0; i < commandHistory.size(); ++i)
    {
        std::cout << "Command " << i + 1 << ":";
        switch (commandHistory[i])
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

const bool Lexer::addCommand(const Command c){
    commandHistory.push_back(c);
    return true;
}

//#define TEST //remove to compile with test main.

#ifdef TEST

int main(){

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