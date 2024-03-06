#include <iostream>
#include <cstring>
using namespace std; // incepand cu laboratorul urmator, nu o sa mai folosim

class Student {
private:
    char *nume;
public:
    // aici vom adauga functiile (metodele) din clasa
    // si ulterior vom imparti in fisiere .h si .cpp

    // Constructor
    Student(const char* nume)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    // Constructor de copiere
    Student(const Student& other)
    {
        this->nume = new char[strlen(other.nume) + 1];
        strcpy(this->nume, other.nume);
    }

    Student& operator=(const Student& other)
    {
        cout << "operator=()" << endl;
        if(this != &other)
        {
            delete[] this->nume;
            this->nume = new char[strlen(other.nume) + 1];
            strcpy(this->nume, other.nume);
        }
        return *this;
    }

    // getters & setters
    char* getNume() const
    {
        return this->nume;
    }

    void setNume(const char* nume)
    {
        if(nume == NULL)
            return;
        delete[] this->nume;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    ~Student()
    {
        cout << "~Student()" << endl;
        delete[] this->nume;
    }
};

void f()
{
    Student s = Student("test");
    // fac ceva cu s
}
int main()
{
    // aici vom testa functionalitatea clasei Student
    char numeStudent[] = "Ionescu";
    Student student = Student(numeStudent);
    cout << student.getNume() << endl;
    student.setNume("Gigel");
    cout << student.getNume() << endl;

    Student s2 = Student(student);
    s2.setNume("Mihai");
    cout << s2.getNume() << endl;

    // s2.operator=(student);
    student = s2;

    cout << student.getNume() << endl;

    return 0;
}