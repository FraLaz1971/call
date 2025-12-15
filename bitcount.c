#include <stdio.h>
#include <stdlib.h>
/* bitcount: count 1 bits in x */
int bitcount(unsigned short x);
int main(int argc,char **argv){
  int b;
  unsigned short int x;
  if (argc<2) {
    fprintf(stderr,"usage: %s <natural number (0,65535)>\n",argv[0]);
    return 1;
}
  x=atoi(argv[1]);
  b=bitcount(x);
  printf("%hu contained %d 1\n",x,b);
  return 0;
}
int bitcount(unsigned short x)
{
 int b;
 for (b = 0; x != 0; x >>= 1)
 if (x & 01)
  b++;
 return b;
}
