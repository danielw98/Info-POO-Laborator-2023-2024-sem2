#include <iostream>

// template <class T> works as well, but <typename T> is preferred
template<typename T>
T Max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Demonstrating with int
    int iMax = Max(5, 7);
    std::cout << "Maximum (int): " << iMax << std::endl;

    // Demonstrating with double
    double dMax = Max(6.34, 18.523);
    std::cout << "Maximum (double): " << dMax << std::endl;

    // Demonstrating with char
    char cMax = Max('a', 'z');
    std::cout << "Maximum (char): " << cMax << std::endl;

    return 0;
}