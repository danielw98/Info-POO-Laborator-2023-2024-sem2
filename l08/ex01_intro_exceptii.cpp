#include <iostream>
#include <stdexcept>

int divide(int numarator, int numitor) {
    if (numitor == 0)
        throw std::runtime_error("Divizie prin zero detectata - nu este posibila.");
    return numarator / numitor;
}

int main()
{
    try {
        std::cout << divide(10, 0) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "A fost prinsa o exceptie: " << e.what() << std::endl;
    }
    return 0;
}
