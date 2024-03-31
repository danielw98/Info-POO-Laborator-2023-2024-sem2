#include <iostream>

// Clasa de baza comuna
class Baza {
public:
    Baza() { std::cout << "Constructor Baza\n"; }
    virtual void afiseaza() const { std::cout << "Afisare din Baza\n"; }
    virtual ~Baza() { std::cout << "Destructor Baza\n"; }
};

// Prima clasa derivata, mosteneste virtual Baza
class Derivata1 : virtual public Baza {
public:
    Derivata1() { std::cout << "Constructor Derivata1\n"; }
    void afiseaza() const override { std::cout << "Afisare din Derivata1\n"; }
    ~Derivata1() { std::cout << "Destructor Derivata1\n"; }
};

// A doua clasa derivata, mosteneste virtual Baza
class Derivata2 : virtual public Baza {
public:
    Derivata2() { std::cout << "Constructor Derivata2\n"; }
    void afiseaza() const override { std::cout << "Afisare din Derivata2\n"; }
    ~Derivata2() { std::cout << "Destructor Derivata2\n"; }
};

// Clasa care mosteneste de la ambele clase derivate
class MostenireDubla : public Derivata1, public Derivata2 {
public:
    MostenireDubla() { std::cout << "Constructor MostenireDubla\n"; }
    void afiseaza() const override { std::cout << "Afisare din MostenireDubla\n"; }
    ~MostenireDubla() { std::cout << "Destructor MostenireDubla\n"; }
};

int main() {
    MostenireDubla obj;
    obj.afiseaza();  // Demonstreaza apelarea metodei corecte
    return 0;
}