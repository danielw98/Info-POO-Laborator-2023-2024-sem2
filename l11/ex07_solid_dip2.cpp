#include <iostream>

// Interfata abstracta pentru accesul la date de orice tip
// Consola, BD, Cloud, Fisier, FTP, SSH, etc...
class IDataAccess {
public:
    // Metoda pur virtuala pentru citirea datelor de orice tip.
    virtual void ReadData() = 0;
};

// Implementare concreta a interfetei IDataAccess pentru accesul la baza de date.
class DataAccess : public IDataAccess {
public:
    void ReadData() override {
        std::cout << "Reading data from database." << std::endl;
    }
};

// Implementare concreta a interfetei IDataAccess pentru accesul la fisiere.
class FileDataAccess : public IDataAccess {
public:
    void ReadData() override {
        std::cout << "Reading data from a file." << std::endl;
    }
};

// Clasa BusinessLogic foloseste o instanta de IDataAccess pentru a procesa date.
class BusinessLogic {
private:
    // Pointer catre interfata IDataAccess pentru dependinta.
    IDataAccess *dataAccess;
public:
    // Constructor care primeste un pointer la interfata IDataAccess.
    BusinessLogic(IDataAccess *da) : dataAccess(da) {}
    
    // Metoda ce foloseste serviciul IDataAccess pentru a procesa datele.
    void ProcessData() {
        dataAccess->ReadData();
    }
};

int main()
{
    // Implementare concreta a interfetei IDataAccess in doua feluri

    // Crearea unei instante a clasei concrete DataAccess.
    DataAccess dataAccess;
    // Crearea unei instante a clasei concrete FileDataAccess.
    FileDataAccess fileDataAccess;

    // Dependency Injection in clasa de BusinessLogic a clasei DataAccess
    // Se va inregistra ca IDataAccess
    BusinessLogic businessLogicDB(&dataAccess);
    businessLogicDB.ProcessData();  // Afiseaza: Reading data from database.

    // Dependency Injection in clasa de BusinessLogic a clasei FileDataAccess
    // Se va inregistra ca IDataAccess
    BusinessLogic businessLogicFile(&fileDataAccess);
    businessLogicFile.ProcessData();  // Afiseaza: Reading data from a file.

    return 0;
}
