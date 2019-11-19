#ifndef COMMAND_OPERATION_H
#define COMMAND_OPERATION_H

#include "commandEnum.h"
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