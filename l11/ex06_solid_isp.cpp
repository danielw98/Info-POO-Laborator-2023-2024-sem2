#include <iostream>

class IPrinter {
public:
    virtual void PrintDocument() = 0;
};

class IScanner {
public:
    virtual void ScanDocument() = 0;
};

class SimplePrinter : public IPrinter {
public:
    void PrintDocument() override {
        std::cout << "Printing Document with Simple Printer..." << std::endl;
    }
};

class SimpleScanner : public IScanner {
public:
    void ScanDocument() override {
        std::cout << "Scanning Document with Simple Scanner..." << std::endl;
    }
};

class MultiFunctionMachine : public IPrinter, public IScanner {
public:
    void PrintDocument() override {
        std::cout << "Printing Document with Multi Functional Machine..." << std::endl;
    }
    void ScanDocument() override {
        std::cout << "Scanning Document with Multi Functional Machine..." << std::endl;
    }
};

int main() 
{
    // Crearea obiectelor pentru fiecare dispozitiv
    SimplePrinter simplePrinter;
    SimpleScanner simpleScanner;
    MultiFunctionMachine multiFunctionalMachine;

    // Demonstrarea principiului Interface Segregation (ISP)
    std::cout << "Using Simple Devices:" << std::endl;
    simplePrinter.PrintDocument();  // Utilizarea imprimantei simple
    simpleScanner.ScanDocument();   // Utilizarea scanerului simplu

    std::cout << "\nUsing MultiFunctional Device:" << std::endl;
    // Utilizarea dispozitivului multifunctional pentru imprimare
    multiFunctionalMachine.PrintDocument();
    // Utilizarea dispozitivului multifunctional pentru scanare  
    multiFunctionalMachine.ScanDocument();

    return 0;
}
