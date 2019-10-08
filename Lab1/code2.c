#include <stdio.h>
//Leap year program
int isLeap(int n){
  if(n%100==0){
    if(n%400==0){
      return 1;
    }else{
      return 0;
    }
  }else{
    if(n%4==0){
      return 1;
    }else{
      return 0;
    }
  }
}

void main(){
  int year;
  printf("Enter a year to be checked:");
  scanf("%d",&year);
  int isItLeap = isLeap(year);
  if(isItLeap == 1){
    printf("The year %d is a leap year",year);
  }
  else if(isItLeap==0){
    printf("The year %d is not a leap year",year);
  }
}
