#include <stdio.h>
unsigned short getbits(unsigned short x, int p, int n);
int main(){
  unsigned short x,x1;
  x=0b1000000011000001;
  x1=getbits(x,7,2);
  printf("%d\n",x1);
  x1=getbits(x,15,1);
  printf("%d\n",x1);
  x1=getbits(x,16,2);
  printf("%d\n",x1);
  x1=getbits(x,0,1);
  printf("%d\n",x1);
}

/* getbits: get n bits from position p */
unsigned short getbits(unsigned short x, int p, int n)
{
  if (((p+1-n)<0)||(p>15)||(p<0)||(n<1)||(n>16)){
    fprintf(stderr,"out of range parameter(s)\n");
    return -1;
  }
  return (x >> (p+1-n)) & ~(~0 << n);
 
}

/*
(x >> (7+1-2)) & -(-0 << 2)
(x >> 6) & -(65535<<2)
(x >> 6) & -(65532)
(x >> 6) & 3
*/
