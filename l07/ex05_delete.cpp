#include <iostream>

class FaraCopiere { 
public: 
    FaraCopiere() = default; 
    FaraCopiere(const FaraCopiere&) = delete; // Interzice copierea 
    FaraCopiere& operator=(const FaraCopiere&) = delete; // Interzice atribuirea prin copiere
}; 

int main()
{
    FaraCopiere instanta1;
    FaraCopiere instanta2;

    // function "FaraCopiere::FaraCopiere(const FaraCopiere &)" (declared at line 6) 
    // cannot be referenced -- it is a deleted functionC/C++(1776)
    FaraCopiere instanta3{instanta1};

    // function "FaraCopiere::operator=(const FaraCopiere &)" (declared at line 7) 
    // cannot be referenced -- it is a deleted functionC/C++(1776)
    instanta1 = instanta2;
    return 0;
}