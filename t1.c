#include <stdio.h>
#include <string.h> 
#define MAXDIM 2000
int main(){
  char tempn[MAXDIM][64];
  char part1[28];
  char part2[22];
  int i,j;
  strcpy(part1,"this is the part1");
  strcpy(part2,"this is the part2");
  i=0;
  while(i<MAXDIM){
    for(j=0;j<10;j++){
      snprintf(tempn[i],50,"%d '%s', '%s'\n",i+j,part1,part2);
      printf("%s",tempn[i]);
    }
    i = i+10;
  }
  printf("i: %d\n",i);
  return 0;
}
