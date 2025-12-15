
#include<stdio.h>
#include<stdlib.h>
#define MAXBYTES 4096
void leftpad(char *s, char c);
int main(int argc, char **argv) {
    unsigned char bytes[MAXBYTES];
    char (*buffer)[MAXBYTES/2];
    int i,j,nbytes;
    int debug=1;
    size_t res;
    char *fname;
   FILE *wf;
    if(argc<2){
      fprintf(stderr,"usage:%s <file.row>\n>",argv[0]);
      return 1;
    }
    fname=argv[1];
    buffer = malloc(MAXBYTES*sizeof(char));
   // Open the binary file for reading
   wf = fopen(fname, "rb");

   // Check if file open successfully
   if (!wf) {
       printf("Cannot open file!\n");
       return 1;
   }

   // Read packet data from the file
   nbytes=0;
   while((res = fread(&bytes[nbytes], 1, 1, wf))>0){
     fprintf(stderr,"%2X",bytes[nbytes]);
//     sprintf(&buffer[nbytes*2][nbytes%(MAXBYTES/2)],"%2X",bytes[nbytes]);
     sprintf((char*)&buffer[nbytes*2+nbytes%(MAXBYTES/2)],"%2X",bytes[nbytes]);
     nbytes++;
   }
   // Close the file after reading
   fclose(wf);
   fprintf(stderr,"\n");
   fprintf(stderr,"read %d bytes\n",nbytes);
/*   for(i=0;i<nbytes;i++){
     printf("%hhu ",bytes[i]);
   }
   printf("\n");*/
   for(i=0;i<nbytes;i++){
     leftpad((char*)&buffer[i*2+i],'0');
     printf("%s", (char*)&buffer[i*2+i]);
   }
   free(buffer);
   return 0;
}

void leftpad(char *s,char c){
  int i,slen;
  slen=strlen(s);
  for(i=0;(i<slen)&&(s[i]==' ');++s){
    s[i]=c;
  }
  return ;
}
