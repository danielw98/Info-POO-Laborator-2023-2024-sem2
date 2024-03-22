#include <iostream>

class Baza {
public:
    // avem constructorul implicit
    ~Baza() { std::cout << "Destructor Baza\n"; }
};

class Derivata : public Baza {
public:
    // constructor implicit idem Baza
    ~Derivata() { std::cout << "Destructor Derivata\n"; }
};

// La crearea unui obiect Derivata, output-ul va fi:
// Destructor Derivata
// Destructor Baza

int main()
{
    Derivata derivata;
    // destructor apelat automat cand variabila locala iese din scop
    return 0;
}