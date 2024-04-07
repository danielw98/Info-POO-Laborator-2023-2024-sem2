#include <iostream>

void contor() 
{
    // Valoarea lui cnt persista intre apeluri
    // cnt este initializat doar la primul apel
    // precum o variabila globala, dar vizibila doar
    // in interiorul undei functii.
    static int cnt = 0;
    cnt++;
    std::cout << "Contorul este la: " << cnt << std::endl;
}

int main()
{
    contor();
    contor();
    return 0;
}