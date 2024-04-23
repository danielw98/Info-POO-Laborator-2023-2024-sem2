#include <vector>
#include <string>
#include <iostream>

int main() {
    // Example for int vector
    std::vector<int> intVector = {1, 2, 3, 4, 5};
    std::cout << "intVector: ";
    for (int i : intVector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Example for string vector
    std::vector<std::string> stringVector = {"Hello", "World", "from", "Templates"};
    std::cout << "stringVector: ";
    for (const std::string& str : stringVector) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}