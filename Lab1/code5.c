#include <stdio.h>

float get_mean(float c[],int n){
  int i = 0;
  float sum = 0;
  for(i=0;i<n;i++){
    sum+=c[i];
  }
  float mean;
  mean = (sum/n);
  return mean;
}

float get_mse(float x[], float y[],int n){
  float c[n];
  int i;
  float j;
  for(i=0;i<n;i++){
    j = (x[i] - y[i]);
    j = j*j;
    c[i] = j;
  }
  float mse = get_mean(c,n);
  return mse;
}

void main(){
  int n,i;
  printf("Enter the number of elements in the arrays : ");
  scanf("%d",&n);
  float x[n],y[n];
  printf("Enter elements of the first array :\n");
  for(i=0;i<n;i++){
    scanf("%f",&x[i]);
  }
  printf("Enter elements of the second array :\n");
  for(i=0;i<n;i++){
    scanf("%f",&y[i]);
  }
  float mse = get_mse(x,y,n);
  printf("The mean square error of the two arrays is : %.3f",mse);
}
