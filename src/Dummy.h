#ifndef _Dummy_h_
#define _Dummy_h_

#include <iostream>
#include <string>

namespace pio
{
namespace util
{
class Dummy
{
private:
    Dummy();
    ~Dummy();

public:
    static void Log(std::string message);
};
} // namespace util
} // namespace pio

#endif