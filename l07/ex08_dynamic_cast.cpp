#include <iostream>
#include <vector>

class IAngajat {
public:
    virtual void AfiseazaRol() = 0;
    // virtual destructor daca clasele derivate aloca dinamic memorie
    // sa fie apleat destructorul corect din clasa derivata, nu din baza
    virtual ~IAngajat() {
        std::cout << "~Angajat()\n";
    };
};

class Manager : public IAngajat {
public:
    void AfiseazaRol() override {
        std::cout << "Manager\n";
    }
    void MetodaManager() {
        std::cout << "Metoda specifica manager\n";
    }
    ~Manager() override
    {
        std::cout << "~Manager()" << std::endl;
    }
};

class Inginer : public IAngajat {
public:
    void AfiseazaRol() override {
        std::cout << "Inginer\n";
    }
    void MetodaInginer() { 
        std::cout << "Metoda specifica ingier\n";
    }
    ~Inginer() override
    {
        std::cout << "~Inginer()" << std::endl;
    }
};

void ProceseazaAngajat(IAngajat *angajat) 
{
    Manager *manager;
    Inginer *inginer;
    
    // metoda comuna poate fi apelata direct deoarece este virtuala
    angajat->AfiseazaRol();

    // metodele specifice obiectelor nu pot fi apelate decat dupa downcasting
    if ((manager = dynamic_cast<Manager*>(angajat)) != nullptr) 
        manager->MetodaManager();
    else if ((inginer = dynamic_cast<Inginer*>(angajat)) != nullptr) 
        inginer->MetodaInginer();
    else 
        std::cout << "Tip necunoscut\n";
}

int main() 
{
    std::vector<IAngajat*> angajati;
    angajati.push_back(new Manager());
    angajati.push_back(new Inginer());

    for (IAngajat *angajat : angajati) 
    {
        ProceseazaAngajat(angajat);
        delete angajat;
    }
    return 0;
}
