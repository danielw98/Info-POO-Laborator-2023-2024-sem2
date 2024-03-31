#include <iostream>

// Definirea interfetei
class IForma {
public:
    // Functie virtuala pura
    virtual void Deseneaza() const = 0; 
};


// Implementarea interfetei
class Cerc : public IForma {
public:
    void Deseneaza() const override 
    {
        std::cout << "Desenand un cerc.\n";
    }
};


class Patrat : public IForma {
public:
    void Deseneaza() const override 
    {
        std::cout << "Desenand un patrat.\n";
    }
};

// Utilizarea interfetei
void DeseneazaForma(const IForma& forma) 
{
    // Polimorfism la executie (runtime)
    // Parametrul primit este de tip referinta catre clasa de baza
    // dar se apeleaza functia corecta din clasa derivata trimisa
    forma.Deseneaza(); 
}

int main() {
    Cerc cerc;
    Patrat patrat;

    // Afisare: Desenand un cerc.
    DeseneazaForma(cerc);
    // Afisare: Desenand un patrat.
    DeseneazaForma(patrat);

    return 0;
}