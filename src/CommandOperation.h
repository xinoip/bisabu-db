#ifndef _Command_Operation_h_
#define _Command_Operation_h_

#include "CommandEnum.h"
#include <vector>
#include <string>

class CommandOperation{
    public:
    // no constructor yet.
    // no copy constructor yet.
    // no assignment opr yet.
    // no destructor yet.

    void runOperation();


    private:

    Command oprType;
    std::vector<std::string> tokens;
    unsigned int tokenCount;


};


#endif