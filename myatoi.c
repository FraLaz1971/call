#include <ctype.h>
#include <stdio.h> 
int matoi(char s[]);
 
int main(int argc, char **argv){
   int i=matoi(argv[1]);
   int j=matoi(argv[2]);
   printf("i*j: %i\n",i*j);
   return 0; 
}

 /* atoi: convert s to integer; version 2 */
int matoi(char *s)
{
 int i, n, sign;
 for (i = 0; isspace(s[i]); i++) /* skip white space */
  ;
 sign = (s[i] == '-') ? -1 : 1;
 if (s[i] == '+' || s[i] == '-') /* skip sign */
   i++;
 for (n = 0; isdigit(s[i]); i++)
   n = 10 * n + (s[i] - '0');
 return sign * n;
}

