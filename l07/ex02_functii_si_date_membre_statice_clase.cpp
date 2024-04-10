#include <iostream>

class Student {
private:
    // Variabila statica comuna tuturor instantelor
    static int numarStudenti; 
public:
    
    static void AdaugaStudenti(int numarStudenti_) 
    { 
       numarStudenti += numarStudenti_;
    }
    static int GetNumarStudenti(void) { return numarStudenti; }
};

int Student::numarStudenti = 0;

int main()
{
    // cu obiect
    Student student;
    int nrStudenti = 10;
    student.AdaugaStudenti(nrStudenti); // posibil dar nerecomandat (antipattern)
    std::cout << student.GetNumarStudenti() << std::endl; // idem

    // fara obiect
    Student::AdaugaStudenti(nrStudenti);
    std::cout << Student::GetNumarStudenti() << std::endl;
    
    return 0;
}
