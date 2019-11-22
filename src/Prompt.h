#ifndef _Prompt_h_
#define _Prompt_h_

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
    const std::string deleteWhitespace();

    std::string text;
    std::string status;
    std::string lastInput;

};

#endif