#include <iostream>
#include <string>
#include "Prompt.h"
#include "Lexer.h"

Prompt *Prompt::instancePtr = nullptr;

//Instance pointer returning function for provide creating
//only one Prompt object
Prompt *Prompt::instance()              
                                        
{
    if (!instancePtr)                   
    {
        instancePtr = new Prompt;
    }

    return instancePtr;
}
//Print prompt
void Prompt::print()                    
{
    std::cout << "status : text\n";
    std::cout << ">";
}
//Getting last input
void Prompt::getInput()                 
{
    getline(std::cin, lastInput);
    deleteWhitespace(); 
                        
}
//Sending lastInput to Lexer object
std::string Prompt::sendInput()         
{
    Lexer::instance()->pushInput(lastInput);
    return lastInput;
}

//Deleting whitespaces from lastInput variable(it can be modified)
//as deleting whitespaces for any strings
const std::string Prompt::deleteWhitespace()    
{                                               
    while (lastInput[lastInput.size() - 1] == ' ')
    {
        lastInput.pop_back();
    }
    return lastInput;
}