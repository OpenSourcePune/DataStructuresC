//Circular Queue
#include <stdio.h>
#include <stdlib.h>


int q[10], front=-1, rear=-1, size=10;

void insert(int ele){
  if( (rear+1)%size == front ){
    printf("OVERFLOW!!");
  }
  else if(rear==-1){
    rear = front = 0;
    q[rear] = ele;
  }
  else{
    rear = (rear+1)%size;
    q[rear] = ele;
  }
}

void delete() {
  if(front == -1){
    printf("UNDERFLOW!!");
  }
  else if(front == rear){
    printf("%d\n", q[front]);
  }
  else{
    printf("%d\n", q[front]);
    front = (front + 1)%size;
  }
}

void display(){
  int i;
  if(front != -1){
    for(i=front; i!=rear; i=(i+1)%size){
      printf("%d\n", q[i]);
    }
    printf("%d\n", q[i]);
  }
  else{
    printf("NO ELEMENT!!");
  }
}

void main(){
  int choice;
  do{
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
        }break;
      }
      case 2:{
        delete(); break;
      }
      case 3:{
        display(); break;
      }
      case 4:{printf("---------------------------\n");printf("Exiting...\n");printf("---------------------------\n");
              exit(0);
              }
      default:{printf("---------------------------\n"); printf("ERROR!\n"); printf("---------------------------\n");}
    }
  }while(choice>0 && choice<6);

}
