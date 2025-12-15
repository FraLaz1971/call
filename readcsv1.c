#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 1024
int main(int argc, char **argv){
  FILE *ifp;
  int llen=DIM;
  char line[DIM],*field;
  char *fname;
  if (argc<2){
    fprintf(stderr,"usage:%s <file.csv>\n",argv[0]);
    return 1;    
    }
  fname=argv[1];
  ifp = fopen(fname,"r");
  while(fgets(line,llen,ifp)){
    field=strtok(line,",");
    while(field!=NULL){
      printf("%s ",field);
      field=strtok(NULL,",");
   }
   printf("\n"); 
  }
  fclose(ifp);
  return 0;
}
