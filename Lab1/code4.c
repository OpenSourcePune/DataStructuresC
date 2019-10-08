#include <stdio.h>
#include <math.h>

float get_mean(float a[],int n){
  int i = 0;
  float sum = 0;
  for(i=0;i<n;i++){
    sum+=a[i];
  }
  float mean;
  mean = (sum/n);
  return mean;
}

float get_std_dev(float a[], int n){
  float mean = get_mean(a,n);
  float b[n];
  int i = 0;
  int j;
  for(i=0;i<n;i++){
    j = a[i] - mean;
    b[i] = j*j;
  }
  float var = get_mean(b,n);
  float std_dev = sqrt(var);
  return std_dev;
}

void sort(float a[], int n){
float temp;
int i, j;
  for(i=0;i<n;i++){
    for(j=0;j<n-1;j++){
      if (a[j]>a[j+1]){
        temp = a[j];
        a[j] = a[j+1];
        a[j+1]=temp;
      }
    }
  }
}

float get_mode(float a[], int n) {
   float maxValue = 0;
   int maxCount = 0, i, j;

   for (i = 0; i < n; ++i) {
      int count = 0;

      for (j = 0; j < n; ++j) {
         if (a[j] == a[i])
         ++count;
      }

      if (count > maxCount) {
         maxCount = count;
         maxValue = a[i];
      }
   }
   return maxValue;
}

void main(){
  int n;
  printf("Enter number of elements : ");
  scanf("%d",&n);
  float a[n];
  printf("Enter the elements : ");
  int i = 0;
  for(i=0;i<n;i++){
    scanf("%f",&a[i]);
  }
  float mean = get_mean(a,n),std_dev = get_std_dev(a,n);
  printf("Mean of the entered numbers : %.2f\n",mean);
  printf("Std deviation : %.2f\n",std_dev);
  sort(a,n);
  float mode = get_mode(a,n);
  printf("\n%.2f",mode);
}
