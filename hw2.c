#include <stdio.h>

int main(void) {
  double f(double),g(double,double);
  double a,b,c;
  //f(-15)<0,f(15)>0
  a=-15;
  b=15;
  c=(a+b)/2;  
  while (f(c)>0.000001||f(c)<-0.000001){
    if (g(a,b)==-1){
      b=(a+b)/2;
      c=(a+b)/2;
    }
    else{
      a=(a+b)/2;
      c=(a+b)/2;
    }
  }
  printf("%.5f\n",c);
  return 0;
}
double f(double x){
  double y;
  y=0.0021*x*x*x*x*x+0.00067*(x-13)*(x-13)*(x-13)*(x-13)+46.7*x-100;
  return y;  
}
double g(double x,double y){
  double half;
  half=(x+y)/2;
  if (f(half)*f(x)<0){
    return -1;
  }
  else{
    return 1;
  }
}
