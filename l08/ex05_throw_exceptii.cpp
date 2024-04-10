#include <iostream>
#include <stdexcept>

void VerificaDivizor(int divizor) 
{
    if (divizor == 0)
        throw std::invalid_argument("Divizorul nu poate fi zero.");
}

int main() 
{
    try {
        VerificaDivizor(0);
    } catch (const std::invalid_argument& e) {
        std::cerr << "A fost prinsa o exceptie: " << e.what() << std::endl;
    }
    return 0;
}
