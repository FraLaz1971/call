#include "utils.h"
int debug=0;
int swapword(unsigned short int *w){
int status = 0;
unsigned short int b1,b2;
if (debug) printf("input word:%d\n",*w);
b1=(*w)&255;
b2=(*w)>>8;
if (debug) printf("MSB:%d\n",b2);
if (debug) printf("LSB:%d\n",b1);
if (debug) printf("after swap:\n");
*w=(b1<<8)+b2;
if (debug) printf("output word:%d\n",*w);
return status;
}
void leftpad(char *s,char c){
  int i,slen;
  slen=strlen(s);
  for(i=0;(i<slen)&&(s[i]==' ');++s){
    s[i]=c;
  }
  return ;
}
