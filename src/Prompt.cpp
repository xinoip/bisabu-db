#include <iostream>
#include "Prompt.h"

Prompt* Prompt::instancePtr = nullptr;

Prompt* Prompt::instance(){
    if(!instancePtr){
        instancePtr = new Prompt;
    }

    return instancePtr;
}
void Prompt::print() {
    std::cout << status << " : " << text << "\n";
    std::cout << ">";
}
void Prompt::getInput()
{
    std::cin >> status >> text;
}
void Prompt::sendInput()
{
    
}