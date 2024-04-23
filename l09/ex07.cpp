#include <iostream>

template<typename T>
class UniquePtr {
private:
    T* ptr;
public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}

    ~UniquePtr() { delete ptr; }

    // Deleting copy constructor and assignment operator
    // So we will 'steal' the object, making it unique
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // Move constructor
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // operator= for moving the UniquePtr
    UniquePtr& operator=(UniquePtr&& other) noexcept 
    {
        if (this != &other) 
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    bool isNull() const { return ptr == nullptr; }
};

int main() 
{
    UniquePtr<int> myPtr{new int(10)};
    std::cout << "Value: " << *myPtr << std::endl;

    UniquePtr<int> movedPtr = std::move(myPtr);
    std::cout << "Moved Value: " << *movedPtr << std::endl;
    std::cout << "Original pointer is null: " << myPtr.isNull() << std::endl;

    return 0;
}
