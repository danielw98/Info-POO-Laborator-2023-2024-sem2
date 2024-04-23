#include <iostream>
#include <memory>

int main() 
{
    std::unique_ptr<int[]> intArray(new int[5]{1, 2, 3, 4, 5});

    for (int i = 0; i < 5; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // `intArray` destructor will be automatically called
    // No need to delete[]
    return 0;
}