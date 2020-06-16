#include <stdio.h>
#include <stdlib.h>

typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

union register_type {
    struct {
        DWORD EAX, EBX, ECX, EDX;
    } dword;
    struct {
        WORD AX, BX, CX, DX;
    } word;
    struct {
        BYTE AL, AH, BL, BH, CL, CH, DL, DH;
    } byte;
};

int main()
{
    union register_type test;
    test.dword.EAX = 0x12345678;
    printf("EAX: %x, ax: %x, bx: %x, al: %x, ah: %x, bl: %x, bh:%x\n", test.dword.EAX, test.word.AX, test.word.BX, test.byte.AL, test.byte.AH, test.byte.BL, test.byte.BH);
    test.word.AX = 0x9acd;
    printf("EAX: %x, ax: %x, bx: %x, al: %x, ah: %x, bl: %x, bh:%x\n", test.dword.EAX, test.word.AX, test.word.BX, test.byte.AL, test.byte.AH, test.byte.BL, test.byte.BH);

    return 0;
}
