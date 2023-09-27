#include "header.h"

int main() 
{
    std::vector<int> values = { 1, 2, 3 };
    std::sort(values.begin(), values.end(), [](int a, int b) 
    { 
        return a > b;
    });

    for (int value : values)
    {
        std::cout << value << std::endl;
    }

    std::cout << "Hello world" << std::endl;

    std::cin.get();
}