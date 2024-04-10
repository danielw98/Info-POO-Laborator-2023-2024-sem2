#include <stdio.h>
#include <setjmp.h>

jmp_buf jumpBuffer;

void SecondFunction() 
{
    printf("Intrare in a doua functie\n");
    longjmp(jumpBuffer, 1);
    printf("Aceasta linie nu va fi executata.\n");
}

void FirstFunction() 
{
    if (!setjmp(jumpBuffer)) {
        SecondFunction();
    } else {
        printf("Retur de la longjmp\n");
    }
}

int main() 
{
    FirstFunction();
    return 0;
}