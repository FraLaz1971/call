#include <stdio.h>
#include <string.h>
#define MAXLEN 1024
int main(int argc, char **argv){
    char* token;
    char str[MAXLEN];
    char *fname;
    char *sep; /* separator characters */
    FILE *ifp;
    if(argc<3){
      fprintf(stderr,"usage:%s <file.csv> <separator(s)>\n",argv[0]);
      return 1;
    }
    fname = argv[1];
    sep = argv[2];
    ifp = fopen(fname,"r");
    // Returns first token
    while(fgets(str,MAXLEN,ifp)){
    token = strtok(str, sep);
    // Keep printing tokens while one of the
    // delimiters present in str[].
      while (token != NULL) {
        printf("%s ", token);
        token = strtok(NULL, sep);
      }
/*     puts(""); */
    }
    fclose(ifp);
  return 0;
}
