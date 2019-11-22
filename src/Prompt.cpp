#include <iostream>
#include <string>
#include "Prompt.h"
#include "Lexer.h"

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
    deleteWhitespace();             //deleting whitespaces from lastInput variable(it can be modified)
                                    //as deleting whitespaces for any strings
}
std::string Prompt::sendInput()
{   
    Lexer::instance()->pushInput(lastInput);
    return lastInput;
}
const std::string Prompt::deleteWhitespace(){
    while(lastInput[lastInput.size()-1] == ' '){
        lastInput.pop_back();
    }
    return lastInput;
}