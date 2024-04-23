#include <iostream>

template<typename T>
class Container {
private:
    T value;
public:
    Container(T v) : value(v) {}
    void print() const {
        std::cout << "Generic Container: " << value << std::endl;
    }
};

template<>
class Container<char> {
private:
    char value;
public:
    Container(char v) : value(v) {}
    void print() const 
    {
        std::cout << "Char Container: value is a character: " 
                  << value << std::endl;
    }
};

int main() 
{
    Container<int> intContainer(123);
    intContainer.print();

    Container<char> charContainer('A');
    charContainer.print();

    return 0;
}