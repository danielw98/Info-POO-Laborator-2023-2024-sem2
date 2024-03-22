#include <iostream>
class Baza {
public:
    Baza() { std::cout << "Constructor Baza\n"; }
};

class Derivata : public Baza {
public:
    Derivata() { std::cout << "Constructor Derivata\n"; }
};

// La crearea unui obiect Derivata, iesirea va fi:
// Constructor Baza
// Constructor Derivata

int main()
{
    Derivata derivata;
    return 0;
}