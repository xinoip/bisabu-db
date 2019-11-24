#include <iostream>
#include <chrono>
#include <ctime>
#include "Prompt.h"
#include "Lexer.h"

int main(int argc, char const *argv[])
{
    std::cout << "cli params ( " << argc << " ): ";
    if(argc >= 1) {
        for (int i = 0; i < argc; i++)
        {
            std::cout << argv[i] << " ";
        }
    }
    std::cout << "\n============== \n" << std::endl;

    auto start = std::chrono::system_clock::now();
    std::time_t startTime = std::chrono::system_clock::to_time_t(start);

    /////////////////////
    // RUN TIME START   
    /////////////////////

    Prompt *prompt = Prompt::instance();
    Lexer *lexer = Lexer::instance();

    prompt->greet();

    int i = 5;
    while (i < 10)
    {
        prompt->print();
        prompt->getInput();
        prompt->sendInput();
        lexer->processInputHistory(' ');
        lexer->processCommands();
        i++;
    }

    prompt->closing();

    /////////////////////
    // RUN TIME END   
    /////////////////////

    auto end = std::chrono::system_clock::now();
    std::time_t endTime = std::chrono::system_clock::to_time_t(end);
    std::chrono::duration<double> elapsedTime = end - start;

    std::cout << "\n\n ===== TIMINGS ===== \n";
    std::cout << "Program started at: " << std::ctime(&startTime) << "\n";
    std::cout << "Program ended at: " << std::ctime(&endTime) << "\n";
    std::cout << "Elapsed time: " << elapsedTime.count() << "s\n";
    std::cout << std::endl;

    return 0;
}
