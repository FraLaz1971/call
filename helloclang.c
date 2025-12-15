#include <stdio.h>
#include <stdlib.h>
#include "fun1.h"
int main(int argc, char **argv){
  int n;
  FILE *fp;
  struct contact mycont[100];
  printf("n. arguments:%d\n",argc);
  for(n=0;n<argc;n++){
    printf("argv[%d]=%s\n",n,argv[n]);
  }
  fp=fopen("myclang.txt", "w");
  if (fp==NULL) {
        printf("error in opening file");
        exit(1);
      } else {
        fprintf(fp,"hello clang file!");
      }
  fclose(fp);
  printf("file myclang.txt created\n");
 load_contact(mycont);
 print_contact(mycont);
  return 0;
}

