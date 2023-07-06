#include <stdio.h>
#include <stdint.h>

typedef uint8_t   BYTE;
typedef uint32_t  DWORD;

int main(void)
{
    printf("%lu\n", sizeof(BYTE));
    printf("%lu\n", sizeof(DWORD));
}