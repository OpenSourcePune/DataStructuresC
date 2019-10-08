#include <stdio.h>
#include <stdlib.h>

int i=0,j=0;
char stack[10]="236*2/+8+";
char op1,op2;
int top=sizeof(stack)-1, size=11;

void push(char ele){
  if(top == size-1){
    //printf("STACK OVERFLOW!!!");
    exit(0);
  }
  else{
    stack[++top] = ele;
  }
}

char pop(){
  if(top == -1){
    printf("UNDERFLOW!!");
  }
  else{
    return stack[top--];
  }
}

void display(){
  int i;
  for(i=0; i<=top; i++){
    printf("%c ", stack[i]);
  }
}

void main(){
  printf("%c",pop());
  while(stack[i]!='\0'){
    if(stack[i]=='+'||stack[i]=='-'||stack[i]=='*'||stack[i]=='/'){
      op1=pop();
      op2=pop();
      switch(stack[i]){
        case '+':{push(op1+op2);
                  break;
                }
        case '-':{push(op1-op2);
                  break;
                }
        case '*':{push(op1*op2);
                  break;
                }
        case '/':{push(op1/op2);
                  break;
                }
      }
    }
    else{
      push(stack[i]-'0');
    }
    }
  display();
  printf("19");
}
