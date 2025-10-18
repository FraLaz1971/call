#include <stdio.h>
#include <limits.h>

void print_bin(unsigned char byte)
{
    int i = CHAR_BIT; /* however many bits are in a byte on your platform */
    while(i--) {
        putchar('0' + ((byte >> i) & 1)); /* loop through and print the bits */
    }
}

int main()
{
  unsigned short int w;
  unsigned char b1,b2;
  w=31752;
  printf("w:%d\n",w);
  b1=w&255;
//  b2=w&65280;
  b2=w>>8;
  printf("b1:%d\n",b1);
  printf("b2:%d\n",b2);
  w = (b1<<8)+b2;
  printf("now w:%d\n",w);

  return 0;
}
