#include <stdio.h>
#include <stdlib.h>

void addCoefficients(){
  int m,n,i;
  int *a,*b,*c,*maxp;
  int max,min;
  printf("Enter the degree of the first polynomial : ");
  scanf("%d",&m);
  printf("Enter the degree of the second polynomial : ");
  scanf("%d",&n);

  a = (int *)malloc(sizeof(int)*(m+1));
  b = (int *)malloc(sizeof(int)*(n+1));

  if(m>=n){
    c = (int *)malloc(sizeof(int)*(m+1));
    max = m;
    min = n;
    maxp = a;
  }else{
    c = (int *)malloc(sizeof(int)*(n+1));
    max = n;
    min = m;
    maxp = b;
  }

  printf("Enter coefficients of first polynomial(start from constant) :\n");
  for(i=0;i<=m;i++){
    scanf("%d",(a+i));
  }

  printf("Enter coefficients of second polynomial(start from constant) :\n");
  for(i=0;i<=n;i++){
    scanf("%d",(b+i));
  }

  for(i=0;i<=min;i++){
    (*(c+i)) = (*(a+i)) + (*(b+i));
  }
  for(i;i<=max;i++){
    (*(c+i)) = (*(maxp+i));
  }

  printf("The resultant polynomial is : \n");
  for(i=0;i<=max;i++){
    printf("%d ",(*(c+i)));
  }
}

void main(){
  addCoefficients();
}
