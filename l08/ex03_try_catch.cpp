#include <iostream>
#include <stdexcept>

void PoateGeneraExceptie(bool genereaza) {
    if (genereaza) {
        throw std::runtime_error("Exceptie generata intentionat.");
    }
    std::cout << "Executie fara exceptie." << std::endl;
}

int main() 
{
    try {
        PoateGeneraExceptie(true);
    } catch (const std::runtime_error& e) {
        std::cerr << "A fost prinsa o exceptie: " << e.what() << std::endl;
    }
    return 0;
}
