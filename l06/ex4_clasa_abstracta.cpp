#include <iostream>

// Definirea clasei abstrate – este neinstantiabila (are metoda virtuala pura)
class FormaAbstracta {
private:
    // pot exista date membre in cadrul unei clase abstracte
public:
    // Metoda oarecare - nu mai avem o interfata ci o clasa abstracta
    // Metoda poate fi de asemenea virtuala dar cu corpul implementat
    void AfiseazaInformatii() { std::cout << "Forma\n"; }
    // Functie virtuala pura
    virtual void Deseneaza() const = 0; 
};

// Implementarea interfetei
class Cerc : public FormaAbstracta {
public:
    void Deseneaza() const override 
    {
        std::cout << "Desenand un cerc.\n";
    }
};

class Patrat : public FormaAbstracta {
public:
    void Deseneaza() const override 
    {
        std::cout << "Desenand un patrat.\n";
    }
};

// Utilizarea clasei abstracte
void DeseneazaForma(const FormaAbstracta& forma) {
    // Polimorfism la executie (runtime)
    forma.Deseneaza(); 
}

int main() {
    Cerc cerc;
    Patrat patrat;

    cerc.AfiseazaInformatii();
    patrat.AfiseazaInformatii();

    DeseneazaForma(cerc);
    DeseneazaForma(patrat);

    return 0;
}