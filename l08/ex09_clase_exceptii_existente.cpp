#include <iostream>
#include <stdexcept>

void FunctieRiscanta() {
    // Simulam detectarea unei conditii eronate
    throw std::invalid_argument("Argument invalid furnizat.");
}

int main() {
    try {
        FunctieRiscanta();
    } catch (const std::invalid_argument& e) {
        std::cerr << "A fost prinsa o exceptie de tip invalid_argument: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Prindem orice alt tip de exceptie derivata din std::exception
        std::cerr << "A fost prinsa o exceptie: " << e.what() << std::endl;
    }
    return 0;
}
