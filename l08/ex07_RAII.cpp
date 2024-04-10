#include <iostream>
#include <fstream>

class Fisier {
private:
    std::ofstream fisier;
public:
    Fisier(const std::string& numeFisier) {
        fisier = std::ofstream(numeFisier);
        std::cout << "Fisier deschis." << std::endl;
    }
    void Scrie(const std::string& mesaj) {
        if (!fisier.is_open()) {
            throw std::runtime_error("Fisierul nu este deschis.");
        }
        fisier << mesaj << std::endl;
    }
    ~Fisier() {
        fisier.close();
        std::cout << "Fisier inchis." << std::endl;
    }
};

int main() 
{
    try {
        Fisier jurnal("jurnal.txt");
        jurnal.Scrie("Prima linie in jurnal.");
        throw std::runtime_error("O exceptie generata intentionat.");
    } catch (const std::exception& e) {
        std::cerr << "Exceptie prinsa: " << e.what() << std::endl;
    }
    return 0;
}
