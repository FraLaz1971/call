#include<stdio.h>
#include<stdlib.h>
int print_array(int (*arr)[2]);
int main(){
  int i;
  int (*arr)[2]=malloc(sizeof(int[16][2]));

/*int (*arr)[M] = malloc(sizeof(int[N][M]));*/
  for(i=0;i<32;++i)
    arr[i%16][i/16]=i;
  print_array(arr);
  free(arr);
  return 0;
}
int print_array(int (*arr)[2]){
  int i;
  for(i=0;i<32;++i)
    printf("%d ",arr[i%16][i/16]);
  return 0;
}
