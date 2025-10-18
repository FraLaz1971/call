#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int escape(char* s, char* t);
/*
Write a function escape(s,t) that converts characters
like newline and tab into visible escape sequences
like \n and \t as it copies the string t to s.
Use a switch. Write a function for the	
other direction as well, converting escape sequences 
into the real characters.		
*/
int main(int argc, char **argv){
  char s[1024], *line;
  int  res;
  size_t linelen=1024;
  line=(char *)malloc(linelen*sizeof(char));
  while(getline(&line,&linelen,stdin)>0){
    res=escape((char *)s,line);
    printf("s: %s t: %s\n",s,line);
  }
  free(line);
  return 0;
}
int escape(char* s, char* t){
  int i,a;
  a=0;
  for (i=0;i<strlen(t);++i){
    switch (t[i]){
      case '\t':
        s[i+a]='\\';
        s[i+1+a]='t';
        ++a;
      break;
      case '\n':
        s[i+a]='\\';
        s[i+1+a]='n';
        ++a;
      break;
      case '\v':
        s[i+a]='\\';
        s[i+1+a]='v';
        ++a;
      break;
      default:
        s[i+a]=t[i];
  }
  }
  s[i+a]='\0';
  return 0;
}
