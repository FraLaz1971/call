#include <stdio.h>
#include <stdlib.h>
#define MAXDIM 10000
int main(int argc,char **argv){
  int i,j;
  int m, n;
  int (*matr)[MAXDIM]=(int **)malloc(MAXDIM*MAXDIM*sizeof(int));
  int **matrp;
  if(argc<3){
    printf("usage: %s <m> <n>\n",argv[0]);
    return 1;
  }
  m=atoi(argv[1]); n=atoi(argv[2]);
  matrp=(int **)realloc(matr,m*n*sizeof(int));
  for (i=0; i<m; i++)
    for (j=0; j<n; j++)
      matrp[i][j]=i*j+i+j;
  for (i=0; i<m; i++){
    for (j=0; j<n; j++)
      printf("%d ",matrp[i][j]);
  printf("\n");
  }
  free(matrp);
  return 0;
}
