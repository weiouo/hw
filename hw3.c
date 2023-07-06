#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int a,b,c,sum;
  float n=0;
  int i;
  int f();
  unsigned seed;
  seed=time(NULL);
  srand(seed);
  for (i=1;i<=1000;i++){
    a=rand()%6+1;
    b=rand()%6+1;
    c=rand()%6+1;
    sum=a+b+c;
    if (f()==0){
      if (sum%2!=0){
        n=n+1;
        if (a==b && b==c){
          n=n-1;}
      }  
    }
    else{
     if (sum%2==0){
        n=n+1;
        if (a==b && b==c){
          n=n-1;}
        }  
      } 
    }
  n=(n/1000)*100;
  printf("%f\%\n",n);
  }
int f(){
  int x;
  x=rand()%2+0;//0=odd 1=even
  return x;
}