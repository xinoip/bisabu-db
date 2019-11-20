#include "Prompt.h"

Prompt* Prompt::instancePtr = nullptr;

Prompt* Prompt::instance(){
    if(!instancePtr){
        instancePtr = new Prompt;
    }

    return instancePtr;
}

