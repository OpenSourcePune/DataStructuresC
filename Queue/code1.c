#include <stdio.h>
#include <stdlib.h>

//Simple Queue implementation


int q[10], front=-1, rear=-1, size=10;

void insert(int ele){
  if(rear+1 == size){
    printf("OVERFLOW!!");
  }
  else if(rear == -1){
    rear = front = 0;
    q[rear] = ele;
  }
  else{
    q[++rear] = ele;
  }
}

int delete(){
  int ele;
  if(front == -1){
    printf("UNDERFLOW!!");
  }
  else if(front == rear){
    ele = q[front];
    front = rear = -1;
    return ele;
  }
  else{
    return (q[front++]);
  }
}

void display(){
  for(int i=front; i<= rear; i++){
    printf("%d\n", q[i]);
  }
}

void main(){
  int choice, del;
  do
  {


    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {

      case 1:{
        for(int i=1; i<9; i++){
          insert(i);
        }
        break;
      }
      case 2:{
        del = delete();
        printf("%d deleted!", del);
        break;
      }
      case 3:{
              display();
              break;
              }
      case 4:{printf("---------------------------\n");
              printf("Exiting...\n");printf("---------------------------\n");
              exit(0);
              }
      default:{printf("---------------------------\n");
              printf("ERROR!\n"); printf("---------------------------\n");
              }
    }
  }while(choice>0 && choice<6);

}
