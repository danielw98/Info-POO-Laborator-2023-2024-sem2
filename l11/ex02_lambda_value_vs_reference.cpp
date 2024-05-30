#include <iostream>

int main() 
{
    int x = 10;
    auto byValue = [x]() mutable {
        x += 5;
        std::cout << "Inside byValue lambda: " << x << std::endl;
    };
    auto byReference = [&x]() {
        x += 5;
        std::cout << "Inside byReference lambda: " << x << std::endl;
    };

    // x nu este modificat in afara lambda
    byValue();
    std::cout << "After byValue, x: " << x << std::endl;

    // x este modificat in afara lambda
    byReference();
    std::cout << "After byReference, x: " << x << std::endl;
    return 0;
}