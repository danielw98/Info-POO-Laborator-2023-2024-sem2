#include <iostream>
#include <stdexcept>

class EroarePersonalizata : public std::runtime_error {
public:
    EroarePersonalizata(const std::string& mesaj)
        : std::runtime_error(mesaj) {}
};

void FunctieOarecare(void)
{
    throw EroarePersonalizata("A aparut o eroare personalizata.");
}

int main() 
{ 
    FunctieOarecare(); 
    return 0; 
}
