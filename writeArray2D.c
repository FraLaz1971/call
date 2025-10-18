#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv) {
   FILE *ofp;
   char *fname;
   if (argc<4){
     fprintf(stderr,"usage:%s <rows> <columns> <outfile>\n",argv[0]);
     return 1;
   }
   int len1=atoi(argv[1]),\
   len2=atoi(argv[2]), i,j;
   unsigned short (*ptr)[len2] =\
   malloc(len1*len2*sizeof(unsigned short));
   if (ptr == NULL) {
        printf("Allocation Failed");
        exit(1);
    }
   fname=argv[3]; 
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
    free(ptr);
    return 0;
}
