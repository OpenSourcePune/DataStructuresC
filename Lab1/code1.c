#include <stdio.h>
//Prime numbers using functions
int isPrime(int n){
  if(n==1){
    return 1;
  }
  else if(n==2){
    return 0;
  }
  else{
    int j = 2;
    int flag = 0;
    for(j=2;j<(n/2);j++){
      if(n%j==0){
        flag = 1;
        break;
      }
      }
      return flag;
    }
  }

void main(){
  int n;
  printf("Enter a number to verify whether prime or not : \n");
  scanf("%d",&n);

  int flag;
  flag = isPrime(n);
  if(flag==0){
    printf("Given number %d is a prime number\n",n);
  }else{
    printf("Given number %d is not a prime\n",n);
  }
}
