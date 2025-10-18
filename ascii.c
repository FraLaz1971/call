/* Value of Character using
implicit conversion with format specifier.*/
#include <stdio.h>

int main() {
    int i;
    char c[6];
    c[0] = 'A';
    c[1] = 'Z';
    c[2] = 'a';
    c[3] = 'z';
    c[4] = '0';
    c[5] = '9';

    // %d displays the integer value of
    // a character
    // %c displays the actual character
   for(i=0;i<sizeof(c);i++){
    printf("The ASCII value of %c is %d\n", c[i], c[i]);
   }
    return 0;
}
