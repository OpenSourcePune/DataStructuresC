#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *ptr;
};

void push(struct node *top,int ele){
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = ele;
  if((top)==NULL){
    top = temp;
  }else{
    temp->ptr = top;
    top = temp;
  }
}

void pop(struct node *top){
  if(top==NULL){
    //
  }else{
    printf("%d",top->ptr->data);
    top = top->ptr->ptr;
  }
}

void main(){
  struct node *top = (struct node *)malloc(sizeof(struct node));
  top = NULL;
  int ch;
  int ele;
  do{
    printf("Enter a choice:");
    scanf("%d",&ch);
    switch(ch){
      case 1: {
                printf("Enter the value to be pushed into the stack:");
                scanf("%d",&ele);
                push(top,ele);
                break;
              }
      case 2:{
                pop(top);
                break;
              }
      case 3:{
              display(top);
              break;
              }
      case 4:{
              exit(0);
            }
    }
  }while(1);
}
