#include "f1.h"
#include "f2.h"

void f1(void) {
    printf("In F1\n");
    f2();
    f2_f1();
}
