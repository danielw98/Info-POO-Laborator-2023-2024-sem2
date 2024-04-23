#include <iostream>
#include <cassert>

class IntVector {
private:
    int *data;       // Pointer to int array
    size_t size;     // Number of elements currently in the array
    size_t capacity; // Maximum capacity (current size)

public:
    IntVector() : data{ nullptr }, size{ 0 }, capacity{ 0 } {}

    void push_back(int value) 
    {
        if (size == capacity) 
        {
            // We double the capacity because reallocating
            // costs CPU time, and the entire memory segment
            // requires moving, unlike when using realloc(),
            // where there might be space left at the end
            size_t newCapacity = (capacity == 0) ? 2 : capacity * 2;
            int *newData = new int[newCapacity];
            for (size_t i = 0; i < size; ++i) 
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size++] = value;
    }

    int operator[](size_t index) const 
    {
        // We will talk about asserts in more detail verbally
        // and there are links included in the materials
        assert(index < size);
        return data[index];
    }

    ~IntVector() { delete[] data; }
};

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

    // We will talk about asserts in more detail verbally
    // and there are links included in the materials
    T operator[](size_t index) const 
    {
        assert(index < size);
        return data[index];
    }

    ~Vector() { delete[] data; }
};

int main() 
{
    IntVector vec;
    vec.push_back(10);
    vec.push_back(20);
    // Output: 10
    std::cout << "Element at index 0: " << vec[0] << std::endl;
    // Output: 20
    std::cout << "Element at index 1: " << vec[1] << std::endl;

    Vector<int> intVec;
    intVec.push_back(10);
    intVec.push_back(20);

    Vector<std::string> stringVec;
    stringVec.push_back("Hello");
    stringVec.push_back("World");

    // Same output - 10 20 - type int
    std::cout << "Int Vector: " << intVec[0] << ", " << intVec[1] << std::endl;
    // Now, we get the classic "Hello world" - type string
    std::cout << "String Vector: " << stringVec[0] << ", " << stringVec[1] << std::endl;

    return 0;
}