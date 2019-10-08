#include <stdio.h>
void TOH(int n,char S,char M,char D){
  if(n==1){
    printf("Move %d numbered disc from %c to %c\n",n,S,D);
  }else{
    TOH(n-1,S,D,M);
    printf("Move %d numbered disc from %c to %c\n",n,S,D);
    TOH(n-1,M,S,D);
  }
}
void main(){
  int n = 3;
  TOH(n,'S','M','D');
}
