#include <iostream>
class Baza {
public:
    Baza() { std::cout << "Constructor Baza\n"; }
    // Destructor virtual
    ~Baza()
    {
        std::cout << "Destructor Baza\n";
    }
};

class Derivata : public Baza {
public:
    Derivata() { std::cout << "Constructor Derivata\n"; }
    // Destructor
    ~Derivata() { std::cout << "Destructor Derivata\n"; }
};

int main()
{
    Baza* ptr = new Derivata();
    // Fara destructor virtual in Baza, doar destructorul lui Baza ar fi apelat. 
    // In acest caz, este apelat si destructorul derivatei.
    delete ptr;
    return 0;
}
