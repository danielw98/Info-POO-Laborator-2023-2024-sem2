#include <iostream>
#include <string>
#include <variant>

template<typename T>
class ErrorOr {
private:
    std::variant<T, std::string> result;

public:
    explicit ErrorOr(T value) : result(value) {}
    explicit ErrorOr(std::string error) : result(error) {}

    bool isError() const 
    {
        return std::holds_alternative<std::string>(result);
    }

    T& getValue() 
    {
        if (isError()) {
            throw std::logic_error("Accesing error as value");
        }
        return std::get<T>(result);
    }

    std::string getError() const 
    {
        if (!isError()) {
            throw std::logic_error("Accesing value as error");
        }
        return std::get<std::string>(result);
    }
};

int main() 
{
    ErrorOr<int> successResult(42);
    ErrorOr<int> errorResult("An error occurred");

    if (!successResult.isError()) {
        std::cout << "Success result: " << successResult.getValue() << std::endl;
    }

    if (errorResult.isError()) {
        std::cout << "Error: " << errorResult.getError() << std::endl;
    }

    return 0;
}