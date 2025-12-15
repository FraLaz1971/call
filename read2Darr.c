#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
  int res,i;
  FILE *rf;
  char *fname;
  if(argc<2){
    fprintf(stderr,"usage:%s <filename>\n",argv[0]);
    return 1;
  }
  fname=argv[1];
  rf=fopen(fname,"r");
  while((res=fscanf(rf,"%3d",&i))!=EOF){
    printf("%d ",i);
  }
  fclose(rf);
  return 0;
}
