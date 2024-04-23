#include <iostream>

template<typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    Vector() : data(nullptr), size(0), capacity(0) {}

    void push_back(T value) 
    {
        // We double the capacity because reallocating
        // costs CPU time, and the entire memory segment
        // requires moving, unlike when using realloc(),
        // where there might be space left at the end
        if (size == capacity) 
        {
            size_t newCapacity = (capacity == 0) ? 2 : capacity * 2;
            T* newData = new T[newCapacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size++] = value;
    }

    T operator[](size_t index) const {
        assert(index < size);
        return data[index];
    }

    ~Vector() {
        delete[] data;
    }
};

int main() 
{
    Vector<int> intVec;
    intVec.push_back(10);
    intVec.push_back(20);

    Vector<std::string> stringVec;
    stringVec.push_back("Hello");
    stringVec.push_back("World");

    std::cout << "Int Vector: " << intVec[0] << ", " << intVec[1] << std::endl;
    std::cout << "String Vector: " << stringVec[0] << ", " << stringVec[1] << std::endl;
}