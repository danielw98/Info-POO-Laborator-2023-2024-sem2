#include <iostream>

class Baza {
public:
    virtual void Afiseaza() { std::cout << "Afisare din Baza\n"; }
};

class Derivata : public Baza {
public:
    void Afiseaza() override { std::cout << "Afisare din Derivata\n"; }
};

int main() 
{
    Baza *baza1 = new Derivata();
    // Utilizeaza VPTR pentru a apela Afiseaza() din Derivata prin pointer Baza
    baza1->Afiseaza();  

    Derivata deriv = Derivata();
    Baza& baza2 = deriv;
    // Utilizeaza VPTR pentru a apela Afiseaza() din Derivata prin referinta Baza
    baza2.Afiseaza();

    delete baza1;
    
    return 0;
}