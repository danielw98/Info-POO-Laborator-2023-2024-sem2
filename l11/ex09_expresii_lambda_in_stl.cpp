#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Original numbers:";
    for (int n : numbers) {
        std::cout << " " << n;
    }
    std::cout << std::endl;

    // Eliminarea numerelor impare folosind remove_if si lambda
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(),
        [](int x) { 
            return x % 2 != 0;
        }), 
        numbers.end());

    std::cout << "Even numbers:";
    for (int n : numbers) {
        std::cout << " " << n;
    }
    std::cout << std::endl;
    
    return 0;
}