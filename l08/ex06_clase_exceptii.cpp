#include <iostream>
#include <stdexcept>

class EroareMatematica : public std::exception {
public:
    const char* what() const noexcept override {
        return "Eroare matematica generala.";
    }
};

void FunctieRiscanta() {
    throw EroareMatematica();
}

int main(){
    FunctieRiscanta();
    return 0;
}
