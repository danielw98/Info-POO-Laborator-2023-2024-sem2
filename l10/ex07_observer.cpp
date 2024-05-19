#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void Update(const std::string& messageFromSubject) = 0;
};

class Subject {
    std::vector<Observer*> observerList;
public:
    void Attach(Observer* observer) {
        observerList.push_back(observer);
    }
    void Detach(Observer* observer) {
        observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
    }
    void Notify(const std::string& message) {
        for (Observer* observer : observerList) {
            observer->Update(message);
        }
    }
};

class ConcreteObserver : public Observer {
public:
    void Update(const std::string& messageFromSubject) override {
        std::cout << "Observer received: " << messageFromSubject << std::endl;
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer;
    subject.Attach(&observer);
    subject.Notify("Hello Observers!");
    subject.Detach(&observer);
    return 0;
}
