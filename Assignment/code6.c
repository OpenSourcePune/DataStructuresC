#include <stdio.h>
#include <stdlib.h>
//Part 7//
struct node{
  int data;
  struct node *ptr;
}*start=NULL,*t,*end,*npr,*tp,*tn;

void createLinkedList(int n){
  for(int i=0;i<n;i++){
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter data at node %d : ",(i+1));
    scanf("%d",&((*t).data));
    t->ptr = NULL;
    if(start==NULL){
      start = t;
    }else{
      end->ptr = t;
    }
    end = t;
  }
}

void displayLinkedList(struct node * start){
  for(t=start;t->ptr!=NULL;t=t->ptr){
    printf("%d ",t->data);
  }
  printf("%d ",t->data);
  printf("\n");
}

struct node * reverseLinkedList(struct node * start){

    if(start != NULL){
        tp = start;
        t = start->ptr;
        start = start->ptr;
        tp->ptr = NULL;
        while(start != NULL){
            start = start->ptr;
            t->ptr = tp;

            tp = t;
            t = start;
        }
        start = tp;
    }
}

void main(){
  int n;
  struct node *startrev;
  printf("Enter number of nodes in the linked list : ");
  scanf("%d",&n);
  createLinkedList(n);
  printf("Here's your original linked list : ");
  displayLinkedList(start);
  startrev = reverseLinkedList(start);
  displayLinkedList(startrev);
}
