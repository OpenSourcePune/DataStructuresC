#include <stdio.h>
#include <stdlib.h>

void push(int stack[],int ele,int *top,int size){
  if(*top == size - 1){
    printf("Stack overflow");
  }else{
    stack[++(*top)] = ele;
  }
}

int pop(int stack[],int *top,int size){
  if((*top)!=-1){
    printf("%d\n",stack[(*top)--]);
    return stack[(*top)+1];
  }else{
    printf("Stack underflow.");
  }
}

void display(int stack[],int *top){
  for(int i=0;i<=(*top);i++){
    printf("%d ",stack[(*top)-i]);
  }
}

void main(){
  int ch,ele;
  int *stack;
  int n;
  printf("Enter number of elements you want to store in the stack:");
  scanf("%d",&n);
  stack = (int *)malloc(sizeof(int)*n);
  int top = -1;
  int size = 10;
  do{
  printf("Enter a choice:");
  scanf("%d",&ch);
  switch(ch){
    case 1:{
              int ele;
              printf("Enter element to be pushed:");
              scanf("%d",&ele);
              push(stack,ele,&top,size);
              printf("\n");
              break;
            }
    case 2:{
            pop(stack,&top,size);
            printf("\n");
            break;
            }
    case 3: {
              printf("Here is the stack\n");
              display(stack,&top);
              printf("\n");
              break;
            }
    case 4: {
              printf("Exiting!");
              exit(0);
            }
      }}while(1);
}
