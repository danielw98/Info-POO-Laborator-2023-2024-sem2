#include <iostream>
#include <cstdint>

int main()
{
    uint32_t val = 0xDEADBEEF;
    uint16_t *ptr = reinterpret_cast<uint16_t*>(&val);
    *ptr = 0xABCD;

    printf("%X\n", val);
    return 0;
}