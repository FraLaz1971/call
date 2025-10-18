#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
/*reads a binary 16 bit array (little endian) */
int main(int argc,char *argv[]){
  unsigned short int **arr,val;
  int i,j,res;
  FILE *rf;
  int nrows,ncols;
  char *fname;
  if(argc<4){
    fprintf(stderr,"usage:%s <rows> <columns> <file.raw>\n",argv[0]);
    return 1;
  }
  nrows=atoi(argv[1]);
  ncols=atoi(argv[2]);
  fname=argv[3];
  arr = (unsigned short**)malloc(nrows*sizeof(unsigned short*));
  for(i=0;i<nrows;i++)
    arr[i]=(unsigned short *)malloc(ncols*sizeof(unsigned short));
  rf=fopen(fname,"rb");

  for(i=0;i<nrows;i++){
    for(j=0;j<ncols;j++){
      fread(&arr[i][j],2,1,rf);
      printf("%u ",arr[i][j]);
    }
    puts("");
  }
  fclose(rf);
  for(i=0;i<nrows;i++)
     free(arr[i]);
  free(arr);
  return 0;
}
