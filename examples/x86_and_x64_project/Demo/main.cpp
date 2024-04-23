#include <iostream>
#include <thread>

#include "../../../LibCWrapper/LibCWrapper.h"

using namespace std;

int main()
{
    auto wrapperThread = []()
    {
        LibCWrapper wrapper;
        wrapper.logAvailableFunctions();
    };

    std::thread thread(wrapperThread);
    thread.join();

    return 0;
}
