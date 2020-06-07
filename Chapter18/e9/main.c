#include <stdio.h>
#include <stdlib.h>


// Part a
char func_x(int a) {
    return 'c';
}

typedef char Func_ptr(int);
typedef Func_ptr *Ptr_Func;
typedef Ptr_Func Array_Ptr_Func[10];

// Part b

typedef int Func_ptr_2[5];
typedef Func_ptr_2 *Func_2(int);

int *func_b(int a) {
    static int arr[5] = {7, 5, 6, 4, 3};
    return arr;
}



int main()
{
    // Part a
    char (*x[10])(int);
    x[0] = func_x;
    printf("%c\n", (*x[0])(5));

    Array_Ptr_Func m;
    m[0] = func_x;
    printf("%c\n", (*m[0])(5));

    // Part b
    int *b = func_b(10);
    for (int i = 0; i < 5; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    Func_2 *bb = func_b(10);
    for (int i = 0; i < 5; i++) {
        printf("%d ",bb[i]);
    }
    printf("\n");

    return 0;
}
