#include <stdio.h>
#include <stdlib.h>
int binsearch(int x, int v[], int n);
int main(int argc, char *argv[])
{
  int x,n;
  int v[10] = {-1000,-55,-335,0,4,16,65,207,1024,3000};
  if (argc<3){
    printf("usage:%s <int number> <nelements (1,10)>",argv[0]);
    return 1;
  }
  x=atoi(argv[1]);n=atoi(argv[2]);
  printf("%d\n",binsearch(x,v,n));
  return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
   int low, high, mid, debug=0;
   low = 0;
   high = n - 1;
   while (low <= high) {
     mid = (low+high)/2;
     if (debug) printf("low: %d mid: %d high: %d v:%d\n",low,mid,high,v[mid]);
     if (x < v[mid])
       high = mid - 1;
     else if (x > v[mid]){
       low = mid + 1;
       if (debug) printf("now low is %d\n",low);
     }
     else /* found match */
       return mid;
   }
   return -1; /* no match */
}
