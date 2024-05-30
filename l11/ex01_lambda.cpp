#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::cout << "Original vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sortarea vectorului folosind o expresie lambda
    std::sort(numbers.begin(), numbers.end(), 
        [](int a, int b) {
            return a < b;
        }
    );

    std::cout << "Sorted vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Aplicarea unei operatiuni pe fiecare element
    std::for_each(numbers.begin(), numbers.end(), [](int& n) {
        n *= 2;
    });

    std::cout << "Doubled values: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}