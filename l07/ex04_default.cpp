#include <iostream>

class Exemplu { 
public: 
    Exemplu() = default; // Constructor implicit 
    Exemplu(const Exemplu&) = default; // Constructor de copiere 
    Exemplu& operator=(const Exemplu&) = default; // Operator de atribuire 
    ~Exemplu() = default; // Destructor 
}; 

int main()
{
    // apelarea constructorului default fara parametri explicit
    Exemplu exemplu1{};
    // apelare constructor de copiere default explicit
    Exemplu exemplu2{ exemplu1 };
    // apelare operator= default
    exemplu1 = exemplu2;
    // ambii destructori default apelati implicit
    return 0;
}