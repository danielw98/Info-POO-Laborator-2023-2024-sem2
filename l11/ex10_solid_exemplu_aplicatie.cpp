#include <iostream>

// Clasa CustomerData gestionata conform principiului Single Responsibility Principle (SRP)
// Aceasta clasa are ca unica responsabilitate gestionarea datelor clientului.
class CustomerData {
public:
    // Metoda pentru adăugarea datelor unui client
    void AddCustomerData() {
        std::cout << "Adding customer data" << std::endl;
    }
};

// Clasa CustomerUI este responsabila pentru interfata utilizatorului legata de clienti.
// Respecta principiul Single Responsibility avand rolul exclusiv de a interactiona cu utilizatorul.
class CustomerUI {
public:
    // Metoda pentru afisarea datelor clientului pe interfața utilizator
    void DisplayCustomer() {
        std::cout << "Displaying customer on UI" << std::endl;
    }
};

int main()
{
    // Crearea si utilizarea obiectelor claselor CustomerData si CustomerUI
    CustomerData customerData;
    CustomerUI customerUI;

    // Adaugarea si afisarea datelor unui client
    customerData.AddCustomerData();
    customerUI.DisplayCustomer();

    return 0;
}