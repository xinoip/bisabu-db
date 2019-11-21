#include <iostream>
#include <string>
#include "prompt.h"
#include "lexer.h"

Prompt* Prompt::instancePtr = nullptr;

Prompt* Prompt::instance(){
    if(!instancePtr){
        instancePtr = new Prompt;
    }

    return instancePtr;
}
void Prompt::print() {
    std::cout << "status : text\n";
    std::cout << ">";
}
void Prompt::getInput()
{
    getline(std::cin,lastInput);
}
std::string Prompt::sendInput()
{   
    Lexer::instance()->pushInput(lastInput);
    return lastInput;
}