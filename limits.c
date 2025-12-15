#include <limits.h>
#include <float.h>
#include <stdio.h>
int main(){
  printf("UCHAR_MIN: %d UCHAR_MAX: %d\n",0,UCHAR_MAX);
  printf("SCHAR_MIN: %d SCHAR_MAX: %d\n",SCHAR_MIN,SCHAR_MAX);
  printf("USHRT_MIN: %d USHRT_MAX: %d\n",0,USHRT_MAX);
  printf("SHRT_MIN: %d SHRT_MAX: %d\n",SHRT_MIN,SHRT_MAX);
  printf("UINT_MIN: %d UINT_MAX: %u\n",0,UINT_MAX);
  printf("INT_MIN: %d INT_MAX: %d\n",INT_MIN,INT_MAX);
  printf("FLT_MIN: %f FLT_MAX: %f\n",FLT_MIN,FLT_MAX);
  printf("DBL_MIN: %f DBL_MAX: %f\n",DBL_MIN,DBL_MAX);
  printf("FLT_DIG: %d DBL_DIG: %d\n",FLT_DIG,DBL_DIG);
  printf("FLT_EPS.: %g DBL_EPS.: %g\n",FLT_EPSILON,DBL_EPSILON);
  return 0;
} 
