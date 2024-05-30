#include <iostream>
#include <fstream>
#include <memory>

// Interfata pentru logging, conform Dependency Inversion Principle (DIP)
// (Avem un exemplu ulterior doar cu DIP)
class ILogger {
public:
    virtual void Log(const std::string& message) = 0;
    virtual ~ILogger() = default;
};

// Logger concret care scrie in consola
class ConsoleLogger : public ILogger {
public:
    void Log(const std::string& message) override {
        std::cout << "Log: " << message << std::endl;
    }
};

// Logger concret care scrie intr-un fisier
class FileLogger : public ILogger {
    std::ofstream logFile;
public:
    FileLogger(const std::string& filename) {
        logFile = std::ofstream(filename);
        if (!logFile) {
            throw std::runtime_error("Nu s-a putut deschide fisierul de log");
        }
    }

    void Log(const std::string& message) override {
        if (logFile.is_open()) {
            logFile << "Log: " << message << std::endl;
        }
    }

    ~FileLogger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};

// Clasa care gestioneaza procesele de business logic ale utilizatorilor
class UserProcessor {
    std::shared_ptr<ILogger> logger;
public:
    // Constructor cu injectie de dependenta
    UserProcessor(std::shared_ptr<ILogger> logger) : logger(std::move(logger)) {}

    void AddUser(const std::string& userName) {
        // Aici cod pentru logica de adaugare a unui utilizator
        logger->Log("User added: " + userName);
    }
};

int main() 
{
    // Creaza un logger pentru consola si un procesor de utilizatori
    auto consoleLogger = std::make_shared<ConsoleLogger>();
    UserProcessor userProcessor(consoleLogger);
    userProcessor.AddUser("Marian");

    // Creaza un logger pentru fisier si un procesor de utilizatori
    auto fileLogger = std::make_shared<FileLogger>("log.txt");
    UserProcessor userProcessorFile(fileLogger);
    userProcessorFile.AddUser("Ionut");

    return 0;
}
