#include <iostream>

class Exemplu {
public:
    // definitie metoda statica
    static void Mesaj() 
    {
        std::cout << "Aceasta este o functie statica." << std::endl;
    }
};

int main()
{
    Exemplu ex;
    // apel metoda statica din interiorul obiectului – posibil dar anti-pattern
    ex.Mesaj();
    // apel metoda statica fara obiect
    Exemplu::Mesaj();
    return 0;
}
