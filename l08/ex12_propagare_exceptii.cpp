#include <iostream>
#include <stdexcept>

void FunctieNivel3(void) {
    throw std::runtime_error("Eroare la nivelul 3");
}
void FunctieNivel2(void) {
    FunctieNivel3();  // Exceptia aruncata aici va fi propagata mai departe
}
void FunctieNivel1(void) {
    try {
        FunctieNivel2();
    } catch (const std::exception& e) {
        std::cout << "Exceptie prinsa in nivelul 1: " << e.what() << std::endl;
        // Exceptia este gestionata aici, oprind propagarea
    }
}

int main() 
{
    FunctieNivel1();
    return 0;
}
