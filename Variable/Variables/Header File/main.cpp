#include <iostream>
#include "Log.h"



int main()
{
    InitLog();
    std::cout << "Hello World!\n";

    Log("Hello World!");
}
