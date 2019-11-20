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


    while(getline(parser,token,tokenChar)){
        tokens.push_back(token);
    }

    for(int i=0;i<tokens.size();++i) std::cout << tokens[i] << std::endl;

    return tokens;



}

void Lexer::resetHistory(){
    commandHistory.clear();
}

void Lexer::printHistory(){

}

