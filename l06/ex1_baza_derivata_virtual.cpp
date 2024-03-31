#include <iostream>

class Forma {
public:
    virtual void Deseneaza() const 
    {
        std::cout << "Desensnd o forma generica.\n";
    }
};


class Cerc : public Forma {
public:
    void Deseneaza() const override 
    {
        std::cout << "Desenand un cerc.\n";
    }
};


int main()
{
    // obiecte derivate memorate drept pointeri catre obiecte tip clasa de baza (upcasting)
    Forma *forma = new Forma();
    Forma *cerc  = new Cerc();
    // se va afisa: Desensnd o forma generica.
    forma->Deseneaza();
    // se va afisa: Desenand un cerc.
    cerc->Deseneaza();

    delete forma;
    delete cerc;

    // obiecte derivate memorate drept referinte catre obiecte tip clasa de baza (upcasting)
    Forma& forma2 = Forma();
    Cerc cercTmp = Cerc();
    Forma& cerc2 = cercTmp;

    // se va afisa: Desensnd o forma generica.
    forma2.Deseneaza();
    // se va afisa: Desenand un cerc.
    cerc2.Deseneaza();
    return 0;
}
