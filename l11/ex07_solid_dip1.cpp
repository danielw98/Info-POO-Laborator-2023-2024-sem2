#include <iostream>

class IPaymentMethod {
public:
    virtual void Process(double amount) = 0;
};

class CreditCardPayment : public IPaymentMethod {
public:
    void Process(double amount) override {
        // Logica specifica pentru plata cu cardul de credit
        std::cout << "Processing credit card payment for amount: " << amount << std::endl;
    }
};

// Alte clase de payment diferite CashPayment, PayPalPayment, etc.

// Implementare concreta sistem de procesare de tranzactii
// Nu conteaza tipul clasei concrete derivate de payment,
// deoarece toate implementeaza o interfata comuna :-)
class PaymentProcessor {
private:
    IPaymentMethod *paymentMethod;
public:
    PaymentProcessor(IPaymentMethod *method) : paymentMethod(method) {}

    void ProcessPayment(double amount) {
        paymentMethod->Process(amount);
    }
};

int main()
{
    // Implementare concreta a IPaymentMethod pentru credit cards
    CreditCardPayment creditCardPayment;
    PaymentProcessor paymentProcessor(&creditCardPayment);
    // Processing payment-ului folosind metoda de payment injectata cu DI
    paymentProcessor.ProcessPayment(100.0);
    return 0;
}
