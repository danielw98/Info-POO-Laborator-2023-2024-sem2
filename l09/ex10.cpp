#include <iostream>

template<typename... Args>
void PrintAll(Args... args) 
{
    (std::cout << ... << args) << std::endl;
}

int main() 
{
    PrintAll(1, "apple", 3.14, 'c');
    return 0;
}