#include <iostream>

class IForma {
public:
    virtual void Deseneaza() const = 0;
};

class Cerc : public IForma {
public:
    void Deseneaza() const override {
        std::cout << "Desenand un cerc.\n";
    }
};

int main()
{
    // apel de functie din derivata prin pointer catre baza
    IForma *forma1 = new Cerc();
    // Afisare: Desenand un cerc.
    forma1->Deseneaza();
    
    // apel de functie din derivata prin referinta catre baza
    Cerc cerc = Cerc();
    IForma& forma2 = cerc;
    // Afisare: Desenand un cerc.
    forma2.Deseneaza();
    
    delete forma1;

    return 0;
}
