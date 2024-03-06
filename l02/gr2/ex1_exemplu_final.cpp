#include <iostream>
#include <cstring>
using namespace std; // incepand cu laboratorul urmator, nu o sa mai folosim


// struct Ceva {
//     int x;
//     int y;
// };

// void f()
// {
//     Ceva var;
//     Ceva *pVar = &var;
//     int *adrX = &pVar->x;
//     adrX++;
//     *adrX = 20;
//     cout << var.y << endl;
// }


class Student {
private:
    char *nume;
public:
    // aici vom adauga functiile (metodele) din clasa
    // si ulterior vom imparti in fisiere .h si .cpp

    // Constructor
    Student(const char *nume)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    // Constructor de copiere
    Student(const Student& other)
    {
        this->nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
    }

    // Getters & Setters
    char* getNume() const
    {
        char *numeReturnat = new char[strlen(nume) + 1];
        strcpy(numeReturnat, nume);
        return numeReturnat;
    }

    void setNume(const char* nume)
    {
        delete[] this->nume;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    Student& operator=(const Student& other)
    {
        if(this != &other)
        {
            delete[] this->nume;
            this->nume = new char[strlen(other.nume) + 1];
            strcpy(this->nume, other.nume);
        }
        return *this;
    }

    ~Student()
    {
        cout << "~Student() " << nume << endl;
        delete[] nume;
    }
};

// class Ex
// {
// private:
//     Student *student;
// public:
//     Ex()
//     {
//         student = new Student("mihai");
//     }
//     ~Ex()
//     {
//         delete student;
//     }
// };

// void f()
// {
//     Student student = Student("test");
//     return;
// }

void f(int x)
{
    cout << "functie de int" << endl;
}

void f(float x)
{
    cout << "functie de float" << endl;
}

int main()
{
    char nume[] = "Mihai";
    Student student = Student(nume);
    Student s2 = Student(student);
    s2.setNume("George");
    cout << student.getNume() << endl;
    cout << s2.getNume() << endl;

    // s2 = student; // se apeleaza operator=, s2 deja existent
    cout << s2.getNume() << endl;

    return 0;
}