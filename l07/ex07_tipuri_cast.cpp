#include <iostream>

void ExempluCastStilC(void)
{
    double pi = 3.1415926;
    // Cast stil C pentru a converti un double in int
    int pi_int = (int) pi;
}

void ExempluStaticCast(void)
{
    class Baza {};
    class Derivata : public Baza {};
    Baza* b = new Derivata();
    // Conversia unui pointer de la clasa de baza la clasa derivata
    // Daca esueaza conversia – eroare de compilare
    Derivata* d = static_cast<Derivata*>(b);
}

void ExempluConstCast(void)
{
    const int val = 10;
    int* modificabil = const_cast<int*>(&val);
    // Modificam valoarea, chiar daca originalul a fost declarat const
    *modificabil = 20;
}

void ExempluReinterpretCast(void)
{
    // pe Windows 64bit, long long are 8bytes, dimensiunea unui pointer
    long long ptr = 5323;
    // Conversia unui long intr-un pointer char* (in cazul acesta, adresa invalida)
    char* charPtr = reinterpret_cast<char*>(ptr);  
}

int main()
{
    ExempluCastStilC();
    ExempluStaticCast();
    ExempluConstCast();
    ExempluReinterpretCast();
    return 0;
}