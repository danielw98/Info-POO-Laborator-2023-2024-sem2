#include <iostream>
#include <vector>

class Forma {
public:
    virtual void Deseneaza() const 
    {
        std::cout << "Desenand o forma generica.\n";
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
    Forma f = Forma();
    Forma& forma2 = f;
    // se va afisa: Desensnd o forma generica.
    forma2.Deseneaza();

    Cerc cercTmp = Cerc();
    Forma& cerc2 = cercTmp;
    // Cerc& cercRef = cercTmp;


    // se va afisa: Desenand un cerc.
    cerc2.Deseneaza();

    std::vector<Forma*> forme;
    forme.push_back(&forma2);
    forme.push_back(&cercTmp);
    
    return 0;
}
