#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int reverse(char *s);
int main(int argc, char **argv){
  int i, res;
  size_t linelen;
  char *line;
/*  char * fname = argv[1];*/
  linelen=1024;
  line=(char *)malloc(linelen*sizeof(char));
/*  if (argc<2){
    printf("usage: %s <filename>\n",argv[0]);
    return 1;
  }*/
  while (getline(&line,&linelen,stdin)>0){
    res=reverse(line);
    printf("%s\n",line);
  }
}

int reverse(char *s){
  int i,l;
  char t[1024];
  l=strlen(s)-1;
  for (i=0;i<l+1;++i){
    t[i]=s[l-i];
  }
  t[i]='\0';
  for(i=0; i<l+1; ++i)
    s[i]=t[i];
/*  printf("%s: %s %d\n",s,t,l);*/
  return 0;
}
