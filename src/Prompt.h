#ifndef _Prompt_h_
#define _Prompt_h_

#include <string>

class Prompt
{
public:
    static Prompt *instance();

    void print();               //Print prompt
    void greet();               //Print closing message
    void getInput();            //Getting last input
    std::string sendInput();    //Sending input to Lexer object

private:
    Prompt() {}
    Prompt(Prompt &);
    Prompt &operator=(const Prompt &);
    static Prompt *instancePtr;
    const std::string deleteWhitespace();   //Deleting whitespaces from lastInput variable(it can be modified)
                                            //as deleting whitespaces for any strings
    std::string text;
    std::string status;
    std::string lastInput;
};

#endif