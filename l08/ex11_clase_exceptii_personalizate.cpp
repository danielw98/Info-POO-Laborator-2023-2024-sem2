#include <iostream>
#include <stdexcept>
#include <string>

// Clasa de exceptie personalizata derivata din std::runtime_error
class EroareDeConexiune : public std::runtime_error {
private:
    int codEroare;
public:
    EroareDeConexiune(const std::string& mesaj, int cod)
        : std::runtime_error(mesaj), codEroare(cod) {}

    // Metoda pentru obtinerea codului de eroare
    int GetCodEroare() const { return codEroare; }
};

// Functie exemplu care utilizeaza exceptia personalizata
void ConectareLaServer() {
    // Simulam o eroare de conexiune
    throw EroareDeConexiune("Conexiune esuata la server.", 404);
}

int main() {
    try {
        ConectareLaServer();
    } catch (const EroareDeConexiune& e) {
        std::cerr << "A fost prinsa o eroare de conexiune: " << e.what() 
                  << " Cod eroare: " << e.GetCodEroare() << std::endl;
    } catch (const std::exception& e) {
        // Prindem orice alta exceptie
        std::cerr << "Exceptie neasteptata: " << e.what() << std::endl;
    }
    return 0;
}
