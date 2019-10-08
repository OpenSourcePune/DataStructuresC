#include <stdio.h>
#include <stdlib.h>
char stack[20];
int top = -1;
int size = 20;
char P[20]={'2','/','3','*','6'};
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

// void display(){
//   for(int i=0;i<=top;i++){
//     printf("%d ",stack[top-i]);
//   }
// }

void main(){


}
