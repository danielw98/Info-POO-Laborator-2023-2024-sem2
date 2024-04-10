#include <iostream>
#include <stdexcept>

void FunctieCuExceptii(void)
{
    try {
        // Cod ce poate arunca diferite tipuri de exceptii
    } catch (const std::invalid_argument& e) {
        // Tratarea unei exceptii specifice
    } catch (const std::exception& e) {
        // Tratarea oricarei alte exceptii derivate din std::exception
    }
}
