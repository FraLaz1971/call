#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void pow1(double *dval,unsigned long int imax);
void pow2(double *dval,unsigned long int imax);
static unsigned long i;
int main(int argc, char **argv){
  unsigned long imax;
  double dval,t_elaps;
  clock_t tstart, tstop;
  if (argc<2){
    printf("usage:%s <imax>\n",argv[0]);
    return 1;
  }
  imax=atol(argv[1]);
  tstart=clock();
  pow1(&dval,imax);
  tstop=clock();
  t_elaps=(double)(tstop-tstart)/CLOCKS_PER_SEC;
  printf("to compute %f pow1() took %f s\n",dval,t_elaps);
  tstart=clock();
  pow2(&dval,imax);
  tstop=clock();
  t_elaps=(double)(tstop-tstart)/CLOCKS_PER_SEC;
  printf("to compute %f pow2() took %f s\n",dval,t_elaps);
  return 0;
}
void pow1(double *dval,unsigned long int imax){
 for(i=0;i<imax;i++){
   *dval=log((double)i*i*i*i);
 }
 return;
}
void pow2(double *dval, unsigned long int imax){
 for(i=0;i<imax;i++){
   *dval=log(pow(i,4));
 }
 return;
}
