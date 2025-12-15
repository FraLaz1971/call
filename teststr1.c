#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
  unsigned long ul;
  char * ss;
  char *is;
  if(argc<2){
    printf("usage:%s <hexstring>\n",argv[0]);
    return 1;
  }
  is=argv[1];
  ul=strtoul(is,&ss,16);
  printf("ul: %ld\n",ul);
  printf("ss: %s\n",ss);

  return 0;
}
