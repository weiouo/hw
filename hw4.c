#include <stdio.h>

int main(void) {
  int f_1=0;
  int f_2=1;
  int f_3=0;
  int n,i;
  scanf("%d",&n);
  if (n==1){
    printf("result is %d\n",f_1);
  }
  else if(n==2){
    printf("result is %d\n",f_2);
  }
  else{
    for (i=1;i<=(n-2);i++){
      f_3=f_1+f_2;
      f_1=f_2;
      f_2=f_3;
    }
  printf("result is %d\n",f_3);  
  }
  return 0;
}