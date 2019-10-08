#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
  int i;
  char a[100];
  FILE *myFile;
  boolean k;
  myFile = fopen("read.c", "r");

for (i = 0; i < 100; i++){
    fscanf(myFile, "%c", &a[i]);
  }
printf("%s",a);
printf(sizeof(a));
}
