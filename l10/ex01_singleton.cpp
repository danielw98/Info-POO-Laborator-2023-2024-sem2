#include <iostream>

class Singleton {
private:
    static Singleton* instance;
    Singleton() {} // Constructor privat pentru a preveni instantierea.

public:
    Singleton(const Singleton&) = delete; // Prevenim copierea.
    Singleton& operator=(const Singleton&) = delete; // Prevenim atribuirea.

    static Singleton* GetInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void DoSomething() {
        std::cout << "Handling some singleton logic" << std::endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singletonInstance = Singleton::GetInstance();
    singletonInstance->DoSomething();
    return 0;
}