// C++20 is required

// Header for built-in C++ concepts
// But we're defining our own concept
// #include <concepts>

#include <iostream>
#include <vector>
#include <iterator>

template<typename T>
concept IsContainer = requires(T a) {
    std::begin(a);
    std::end(a);
};

template<typename T>
requires IsContainer<T>
void PrintContainer(const T& container) {
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    PrintContainer(vec);
    return 0;
}