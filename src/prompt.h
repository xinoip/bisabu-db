#ifndef PROMPT_H
#define PROMPT_H

#include <string>

class Prompt{
    public:
   
    static Prompt* instance();
    
    void print();
    void getInput();
    std::string sendInput();

    private:
    Prompt(){}
    Prompt(Prompt& ){}
    Prompt& operator=(const Prompt&){}
    static Prompt* instancePtr;

    std::string text;
    std::string status;
    std::string lastInput;

};

#endif