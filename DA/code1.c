#include <stdio.h>
#include <stdlib.h>

void main(){
  int n,i=0;
  printf("Enter number of elements in the array : ");
  scanf("%d",&n);
  int *a = (int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    printf("Enter next element : ");
    scanf("%d",(a+i));
  }

  for(i=0;i<n;i++){
    printf("%d ",*(a+i));
  }
}
