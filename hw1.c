#include <stdio.h>

int main(void) {
  
  int g1, g2, c1, c2, ave;
  printf("Enter grade1\n");
  scanf("%d",&g1);
  while (100<g1 || g1<0){
    scanf("%d",&g1);
  }
  printf("Enter credit1\n");
  scanf("%d",&c1);
  printf("Enter grade2\n");
  scanf("%d",&g2);
  while (100<g2 || g2<0){
    scanf("%d",&g1);
  }
  printf("Enter credit2\n");
  scanf("%d",&c2);
  ave=(g1*c1+g2*c2)/(c1+c2);

  printf("Score1 %d Credit1%d\n",g1,c1);
  printf("Score2 %d Credit2%d\n",g2,c2);
    
  if (ave>=90){
    printf("GPA is A");}
  else if(ave>=80){
    printf("GPA is B");}
  else if(ave>=70){
    printf("GPA is C");}
  else if(ave>=60){
    printf("GPA is D");}
  else{
    printf("GPA is F");}
  return 0;
}