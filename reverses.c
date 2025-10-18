#include <string.h>
#include <stdio.h>
void reverse(char s[]);
int main(int argc, char **argv){
  char *v=argv[1];
  reverse(v);
  printf("%s\n",v);
  return 0;
}
 /* reverse: reverse string s in place */
void reverse(char s[])
{
 int c, i, j;
 for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
   c = s[i];
   s[i] = s[j];
   s[j] = c;
/*   printf("i: %i j: %i\n",i,j); */
 }
}
