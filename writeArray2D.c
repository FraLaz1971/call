#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv) {
   FILE *ofp;
   char *fname;
   int len1,len2, i,j;
   unsigned short **ptr;
   if (argc<4){
     fprintf(stderr,"usage:%s <rows> <columns> <outfile>\n",argv[0]);
     return 1;
   }
   len1=atoi(argv[1]);
   len2=atoi(argv[2]);
   fname=argv[3];
   ptr = (unsigned short **)malloc(len1*sizeof(unsigned short*));
   if (ptr == NULL) {
        printf("Allocation Failed");
        exit(1);
    }
   for(i=0;i<len1;i++){
     ptr[i]=(unsigned short*)malloc(len2*sizeof(unsigned short));
   if (ptr[i] == NULL) {
        printf("Allocation %d Failed",i);
        exit(1);
    }
   }
    // Populate the array
    for (i = 0; i < len1; i++)
      for(j=0;j<len2;j++)
          ptr[i][j] = (i+1)*(j+1);
    ofp = fopen(fname,"wb");
    // save the array to file
    for (i = 0; i < len1; i++)
       for(j=0;j<len2;j++)
 	  fwrite(&ptr[i][j],2,1,ofp);
    fclose(ofp);
   for(i=0;i<len1;i++)
      free(ptr[i]);
    free(ptr);
    return 0;
}
