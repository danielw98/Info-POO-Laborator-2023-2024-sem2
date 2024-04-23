#include <iostream>
#include <memory>

class Demo {
public:
    void show() { std::cout << "Demo::show()" << std::endl; }
};

int main() {
    std::shared_ptr<Demo> ptr1 = std::make_shared<Demo>();
    std::cout << "shared_ptr use count: " << ptr1.use_count() << std::endl;

    std::shared_ptr<Demo> ptr2 = ptr1;
    std::cout << "shared_ptr use count: " << ptr1.use_count() << std::endl;

    ptr2->show();
    std::weak_ptr<Demo> weakPtr = ptr1;
    std::cout << "weak_ptr use count: " << weakPtr.use_count() << std::endl;

    // Check if the object is still managed by any shared_ptr instances
    if (auto spt = weakPtr.lock()) {
        std::cout << "weak_ptr object is still managed with " << weakPtr.use_count() 
                  << " shared references." << std::endl;
    } else {
        std::cout << "weak_ptr object is no longer managed and has been destroyed." 
                  << std::endl;
    }

    return 0;
}