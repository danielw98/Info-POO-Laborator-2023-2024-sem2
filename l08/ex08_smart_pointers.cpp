#include <iostream>
#include <memory>

void Procesare() 
{
    // 'ptr' este un std::unique_ptr<int>
    auto ptr = std::make_unique<int>(42); 
    throw std::runtime_error("Exceptie dupa alocare");
    // Memoria alocata este eliberata automat 
    // la distrugerea lui 'ptr', chiar daca se arunca o exceptie.
}

int main() 
{
    try {
        Procesare();
    } catch (const std::exception& e) {
        std::cerr << "Exceptie prinsa: " << e.what() << std::endl;
    }
}
