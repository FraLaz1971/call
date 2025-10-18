/* C++ program to illustrate the
// strtod() function */
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char str[] = "11.03e 0mn";
    char* end;
    double number;

    number = strtod(str, &end);
    printf("string number = %s\n", str);
    printf("double = %f\n", number);
    printf("end string = %s\n",end);

    return 0;
}
