#include <stdio.h>
#include <stdlib.h>

void main(){
  int r,c;
  printf("Enter rows and columns of the 2D matrix : ");
  scanf("%d %d",&r,&c);
  int *a = (int *)malloc(sizeof(int)*r*c);

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      printf("Enter the next element : ");
      scanf("%d",(a+i*c+j));
    }
  }

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      printf("%d ",*(a+i*c+j));
    }
    printf("\n");
  }
}
