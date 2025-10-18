#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
  if(argc<3){
    fprintf(stderr,"usage:%s <nrows> <ncols>\n",argv[0]);
    return 1;
  }
  int i, j;
  int m=atoi(argv[1]), n=atoi(argv[2]);
  int *matr=(int *)malloc(m*n*sizeof(int));
  for (i=0;i<m*n;i++) matr[i]=i;
  for (i=0;i<m;i++){
    for (j=0;j<n;j++)
      printf("%3d ", matr[i*n+j]);
    printf("\n");
     }
  free(matr);
  return 0;
}
