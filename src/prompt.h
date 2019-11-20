#ifndef PROMPT_H
#define PROMPT_H

#include <string>

class Prompt{
    public:
    Prompt(){}
    Prompt(Prompt& ){}
    static Prompt* instance();
    
    void print();
    void getInput();
    void sendInput();

    private:
    
    Prompt& operator=(const Prompt&){}
    static Prompt* instancePtr;

    std::string text = "text"; //temp string
    std::string status = "status";//temp string
    std::string lastInput;

};

#endif