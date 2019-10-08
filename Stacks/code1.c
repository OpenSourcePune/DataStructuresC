#include <stdio.h>
#include <stdlib.h>
int stack[10];
int top = -1;
int size = 10;

void push(int ele){
  if(top == size - 1){
    printf("Stack overflow");
  }else{
    stack[++top] = ele;
  }
}

int pop(){
  if(top!=-1){
    printf("%d\n",stack[top--]);
    return stack[top+1];
  }else{
    printf("Stack underflow.");
  }
}

void display(){
  for(int i=0;i<=top;i++){
    printf("%d ",stack[top-i]);
  }
}

void main(){
  int ch,ele;
  do{
  printf("Enter a choice:");
  scanf("%d",&ch);
  switch(ch){
    case 1:{
              int ele;
              printf("Enter element to be pushed:");
              scanf("%d",&ele);
              push(ele);
              break;
            }
    case 2:{
            pop();
            break;
            }
    case 3: {
              printf("Here is the stack\n");
              display();
              break;
            }
    case 4: {
              printf("Exiting!");
              exit(0);
            }
      }}while(1);
}
