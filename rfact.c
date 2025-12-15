#include <stdio.h>
#include <stdlib.h>
#ifdef DEBUG
  static int nr=0;
#endif

int fact(int n);

int main(int argc,char **argv){
  int n;
  if(argc <2){
    fprintf(stderr,"usage:%s <natural number [0,32)>\n",argv[0]);
    return 1;
  }
  n=atoi(argv[1]);
  if((n<0)||(n>31)) {
    fprintf(stderr,"enter a natural number in [0,32)\n");
    return 1;
  }
  printf("factorial of %d = %d\n",n,fact(n));
#ifdef DEBUG
  printf("n. of recursions = %d\n",nr);
#endif
  return 0;
}

int fact(int n){
#ifdef DEBUG
  nr++;
#endif
 switch (n){
 case 0:
   return 1;
   break;
 case 1:
   return 1;
   break;
 default:
   return n*fact(n-1);  
 }
}
