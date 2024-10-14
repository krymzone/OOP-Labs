#include <iostream>
using namespace std;

int test_var=10; //variabila globala ( inafara oricarei functie)

int function_test_2();
void ptr_ex_1();

int main()
{
    function_test_2();
    ptr_ex_1();
    return 0
}

int function_test_2()
{
    return 0
}

void ptr_ex_1()
{
    int text_var = 7
    int x = 3
    char y = 'c';
    double d = 2.5;
    int v1[111] = 0;

    int* ptr_test_var = &test_var;
    int* ptr_x = &x;
    char* ptr_y = &y;
    double* ptr_d = &d;

    int a = 3 + x++;
    int b = 3 + ++x;
    x++;
    ptr_x++;

    int* ptr_v1 = &v1;
}
