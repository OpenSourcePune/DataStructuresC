#include <stdio.h>
#include <stdlib.h>

void main(){
  int n, *a, i, j, temp;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  a = (int *)malloc( sizeof(int)*n );
  printf("Input array elements: ");
  for(i=0; i<n; i++){
    scanf("%d", (a+i));
  }
  printf("\nArray in ascending order: ");
  for(i=0; i<n; i++){
    for(j=0; j<n-1; j++){
      if( (a+j)>(a+j+1) ){
        temp=*(a+j);
        *(a+j)=*(a+j+1);
        *(a+j+1)=temp;
      }
    }
  }
  for(i=0; i<n; i++){
    printf("%d ", *(a+i));
  }
  printf("\nArray in descending order: ");
  for(i=n-1; i>=0; i--){
    printf("%d ", *(a+i));
  }
}
