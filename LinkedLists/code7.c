#include <stdio.h>
//Circular linked lists
#include <stdlib.h>

struct node{
  int data;
  struct node *ptr;
}*start=NULL,*t,*end,*npr;

void createCLinkedList(int n){
  for(int i=0;i<n;i++){
    t = (struct node *)malloc(sizeof(struct node));
    t->data = i+1;
    t->ptr = NULL;
    if(start==NULL){
      start = t;
    }else{
      end->ptr = t;
    }
    end = t;
    end->ptr = start;
  }
}

void displayCLinkedList(struct node * start){
  for(t=start;t->ptr!=start;t=t->ptr){
    printf("%d ",t->data);
  }
  printf("%d",t->data);
}

void insertCLinkedList(int pos, int ele){
  t = (struct node *)malloc(sizeof(struct node));
  (*t).data = ele;
  t->ptr = NULL;
  if(pos==1){
    end = start;
    for(end=start;end->ptr!=start;end=end->ptr);
    end->ptr = t;
    t->ptr = start;
    start = t;
  }else{
    npr = start;
    for(int i=2;i<pos&&(npr->ptr!=start);i++){
      npr = npr->ptr;
    }
    t->ptr = npr->ptr;
    npr->ptr = t;
  }
}

void deletionCLinkedList(int pos){
  if(pos==1){
    t = start;
    for(end=start;end->ptr!=start;end=end->ptr);
    end->ptr = t->ptr;
    start = start->ptr;
  }else{
    npr = NULL;
    t = start;
    for(int i=1;i<pos && t->ptr!=start;i++){
      npr = t;
      t = t->ptr;
    }
    npr->ptr = t->ptr;
  }
  free(t);
}

int linearSearchCLinkedList(int ele){
  int flag = 0;
  for(t=start;t->ptr!=start;t=t->ptr){
    if(t->data==ele || end->data==ele){
      flag = 1;
      break;
    }
  }
  return flag;
}

void sortCLinkedList(struct node * start){
  struct node *i,*j;
  int temp;
  for(i=start;i->ptr!=start;i=i->ptr){
    for(j=i->ptr;j!=start;j=j->ptr){
      if(((*i).data)>((*j).data)){
        temp = (*i).data;
        (*i).data = (*j).data;
        (*j).data = temp;
      }
    }
  }
}


void maiin(){
  int NumberOfPeople;
  int pos;
  printf("Enter number of people. : ");
  scanf("%d",&NumberOfPeople);
  createCLinkedList(NumberOfPeople);
  //displayCLinkedList(start);
  int PeopleLeft = NumberOfPeople;
  struct node *temp;
  temp = start;
  while(PeopleLeft!=1){
    temp = (temp->ptr)->ptr;
    pos = temp->data;
    deletionCLinkedList(pos);
    PeopleLeft--;
  }
  printf("The last man is %d", pos);
}






int josephus(int n, int k){
  if (n == 1)
    return 1;
  else
    return (josephus(n - 1, k) + k-1) % n + 1;
}

// Driver Program to test above function
void main(){
  int n;
  int k = 3;
  printf("Enter number of people. : ");
  scanf("%d",&n);
  printf("Enter number of people. : ");
  scanf("%d",&n);
  printf("The last man is %d", josephus(n, k));
}
