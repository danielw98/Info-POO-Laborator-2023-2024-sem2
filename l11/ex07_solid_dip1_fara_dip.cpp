#include <iostream>

// Definirea unei clase concrete pentru procesarea platilor cu cardul de credit
class CreditCardPayment {
public:
    void Process(double amount) {
        std::cout << "Processing credit card payment for amount: " 
                  << amount << " RON." << std::endl;
    }
};

// Clasa PaymentProcessor care utilizeaza direct un obiect CreditCardPayment
class PaymentProcessor {
    CreditCardPayment creditCardPayment;  // Crearea unei instante a clasei CreditCardPayment

public:
    void ProcessPayment(double amount) {
        // Delegarea apelului la metoda Process a clasei CreditCardPayment
        creditCardPayment.Process(amount);
    }
};

int main()
{
    // Crearea unui obiect PaymentProcessor
    PaymentProcessor processor;

    // Procesarea unei plati de 250 RON
    processor.ProcessPayment(250.0);
    
    return 0;
}
