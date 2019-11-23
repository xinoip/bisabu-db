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

//Print greeting message
void Prompt::greet() {
    std::string greetingMessage [5]={
    "              | |                         ",
    " __      _____| | ___ ___  _ __ ___   ___ " ,
    " \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ ",
    "  \\ V  V /  __/ | (_| (_) | | | | | |  __/ ",
    "   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| "
    };
    for (int i = 0; i <5; i++)
    {
        std::cout << greetingMessage[i] << std::endl;
    }
    
}

//Print closing message
void Prompt::closing() {

    std::string closeMessage[6] = {
        "  _____        __     __         _ ",
        " / ____|       \\ \\   / /        | |",
        "| (___   ___  __\\ \\_/ /__  _   _| |",
        " \\___ \\ / _ \\/ _ \\   / _ \\| | | | |",
        " ____) |  __/  __/| | (_) | |_| |_|",
        "|_____/ \\___|\\___||_|\\___/ \\__,_(_)"
    };
     for (int i = 0; i < 6; i++)
    {
        std::cout << closeMessage[i] << std::endl;
    }
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