#include <stdio.h>
#include <stdlib.h>
void squeeze(char s[], int c);
int main(){
  int i;
  size_t linelen=1024;
  char *line;
  line=(char *)malloc(linelen*sizeof(char));
  while(getline(&line,&linelen,stdin)>0){
    squeeze(line, ' ');
    printf("%s",line);
  }
  return 0;
}
/* squeeze: delete all c from s */
 void squeeze(char s[], int c)
 {
 int i, j;
 for (i = j = 0; s[i] != '\0'; i++)
 if (s[i] != c)
 s[j++] = s[i];
 s[j] = '\0';
 }
