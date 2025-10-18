#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv) {
    int len=atoi(argv[1]), i;
   unsigned short *ptr =\
   (unsigned short *)malloc(len*sizeof(unsigned short));

    // Populate the array
    for (i = 0; i < len; i++)
        ptr[i] = i;

    // Print the array
    for (i = 0; i < len; i++)
        printf("%d ", ptr[i]);
    free(ptr);
    return 0;
}
