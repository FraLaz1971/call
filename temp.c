#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
  unsigned short i,j,nmax;
  nmax=atoi(argv[1]);
  j=atoi(argv[2]);
  for(i=0;i<nmax;i++){
    printf("i=%hu i mod %hu = %hu\n",i,j,i%j);
  }
  return 0;
}
