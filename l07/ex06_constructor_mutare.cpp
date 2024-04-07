#include <iostream>

class Mutabil { 
private:
    int *data;
    int count;
public:
    // Constructor standard
    Mutabil(int count_ = 0) : count{ count_ } {
        data = (count == 0) ? nullptr : new int[count];
        // initializare data array, ca sa aiba sens
    } 
    // Constructor de mutare 
    Mutabil(Mutabil&& sursa) noexcept : data{sursa.data}, count{sursa.count} 
    { 
        // am transferat ownership-ul datelor, obiectul curent devine gol
        sursa.data = nullptr;
        sursa.count = 0;
    }
    // operator de atribuire prin mutare
    Mutabil& operator=(Mutabil&& sursa) noexcept 
    {
        if(this == &sursa)
            return *this;
        // toate datele alocate dinamic existente ale obiectului in care mutam
        // trebuiesc eliberate explicit, altfel avem memory leaks
        if(data != nullptr)
            delete[] data;

        // preiau prin shallow copy datele de la obiectul sursa
        data = sursa.data;
        count = sursa.count;
        // golesc obiectul sursa fara sa eliberez memoria
        sursa.data = nullptr;
        sursa.count = 0;
        return *this;
    }
    // Utilizarea =delete pentru a bloca copierea si reatribuirea implicite 
    Mutabil(const Mutabil&) = delete;  // Blocheaza copierea 
    Mutabil& operator=(const Mutabil&) = delete; // Blocheaza atribuirea 
    ~Mutabil() { delete[] data; } // Destructor 
};

Mutabil CreeazaMutabil(int numElems) 
{
    return Mutabil(numElems);
}

void ProceseazaMutabil(Mutabil&& mutabil)
{
    // cod care se ocupa cu un obiect temporar
}
int main()
{
    int numElems = 1000;
    // initializez o instanta cu date de dimensiune relativ mare
    Mutabil instanta1 = Mutabil(numElems);
    // datele din instanta1 sunt mutate in instanta2, instanta1 ramane "goala"
    Mutabil instanta2 = std::move(instanta1);
    // datele din instanta2 au fost mutate in instanta 1 prin op= pentru mutare
    instanta1 = std::move(instanta2);
    // constructor de mutare invocat explicit deoarece avem un rvalue
    Mutabil instanta3 = Mutabil(numElems);
    // obiect temporar returnat prin intermediul constructorului de mutare
    Mutabil instanata4 = CreeazaMutabil(numElems);
    // constructor de mutare apelat pentru swap pentru eficientas
    std::swap(instanta1, instanta3);
    // am creat un obiect temporar rvalue, si il trimit ca parametru la functie
    ProceseazaMutabil(Mutabil(numElems));
    return 0;
}
