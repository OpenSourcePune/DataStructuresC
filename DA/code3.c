#include <stdio.h>
#include <stdlib.h>

void main(){
  int r,c;
  printf("Enter number of rows and columns of the 2D matrix : ");
  scanf("%d %d",&r,&c);
  int **a = (int **)malloc(sizeof(int *)*r);
  for(int i=0;i<r;i++){
    *(a+i) = (int *)malloc(sizeof(int)*c);
  }

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      printf("Enter next element : ");
      scanf("%d",(*(a+i)+j));
    }
  }

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      printf("%d ",*(*(a+i)+j));
    }
    printf("\n");
  }
}
