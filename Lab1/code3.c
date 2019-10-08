#include <stdio.h>

void AP_term_sum(int a,int n, int d){
  int tn;
  int i = 0;
  for(i=0;i<n;i++){
    tn = a + i*d;
    printf("%d\n",tn);
  }
  int sn;
  sn = (n/2)*(a+tn);
  printf("Nth term : %d and Sum of n terms : %d",tn,sn);
}

void main(){
  int a,n,d;
  printf("Enter first term : ");
  scanf("%d",&a);
  printf("Enter n : ");
  scanf("%d",&n);
  printf("Enter difference : ");
  scanf("%d",&d);
  AP_term_sum(a,n,d);
}
