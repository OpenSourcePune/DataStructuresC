#include <stdio.h>
#include <stdlib.h>

void matrixArithmetic(){
  int m,n,p,q,i,j,k,s = 0;
  int *first,*second,*sum,*sub,*mul;
  printf("Note : For addition and subtraction the order of matrices must be same.\n");
  printf("Note : For multiplication the columns of the first = rows of second.\n");
  printf("Enter number of rows of matrix 1: ");
  scanf("%d",&m);
  printf("Enter number of columns of matrix 1: ");
  scanf("%d",&n);
  printf("Enter number of rows of matrix 2: ");
  scanf("%d",&p);
  printf("Enter number of columns of matrix 2: ");
  scanf("%d",&q);
  first = (int *)malloc(sizeof(int)*n*m);
  second =(int *)malloc(sizeof(int)*p*q);
  sum =(int *)malloc(sizeof(int)*n*m);
  sub =(int *)malloc(sizeof(int)*n*m);
  mul = (int *)malloc(sizeof(int)*m*q);
  printf("Enter the elements of first matrix\n");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      scanf("%d",(first+i*n+j));
    }
  }

  printf("Enter the elements of second matrix\n");
  for(i=0;i<p;i++){
    for(j=0;j<q;j++){
      scanf("%d",(second+i*q+j));
    }
  }

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      (*(sum+i*n+j)) = (*(first+i*n+j)) + (*(second+i*n+j));
      (*(sub+i*n+j)) = (*(first+i*n+j)) - (*(second+i*n+j));
      // for(k=0;k<m;k++){
      //   s += (*(first+(i*n+k))) * (*(second+(j+k*m)));
      // }
      // *(mul+i*n+j) = s;
      // s = 0;
    }
  }

  for(i=0;i<m;i++){
    for(j=0;j<q;j++){
      for(k=0;k<p;k++){
        s += (*(first+(i*n+k))) * (*(second+(j+k*q)));
      }
      *(mul+i*q+j) = s;
      s = 0;
    }
  }

  printf("Your addition array:\n");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("%d ",(*(sum+i*n+j)));
    }
    printf("\n");
  }

  printf("Your subtraction array:\n");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("%d ",(*(sub+i*n+j)));
    }
    printf("\n");
  }

  printf("Your multiplication array:\n");
  for(i=0;i<m;i++){
    for(j=0;j<q;j++){
      printf("%d ",(*(mul+i*q+j)));
    }
    printf("\n");
  }
}

void main(){
  matrixArithmetic();
}
