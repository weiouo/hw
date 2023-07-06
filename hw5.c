#include <stdio.h>

int main(void) {
  int arr[9];
  int bubblesort();
  int i=0;
  while(i<9){
    //need a space before %d,in order to clean the "enter action"
    scanf(" %d",&arr[i]);
    i++;
  }
  bubblesort(arr,9);
  printf("after bubble sort:\n");
  for(i=0;i<9;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}
int bubblesort(int array[],int n){
  int x;
  for(x=0;x<n-1;x++){
    int y;
    for(y=0;y<n-x-1;y++){
      //when left>right,the left one become the right one
      if (array[y]>array[y+1]){
        int z=array[y];
        array[y]=array[y+1];
        array[y+1]=z;}
    }
  }
}