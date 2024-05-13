#include <iostream>
#include <cstdint>
union MyUnion {
    uint16_t myShort;
    uint8_t myBytes[2];
};

int main()
{
    MyUnion myUnion;
    myUnion.myShort = 0xABCD;

    printf("%X %X\n", myUnion.myBytes[0], myUnion.myBytes[1]);

    return 0;
}