#include <stdio.h>
#include <stdlib.h>

struct node {
  int data1;
  int head;
  struct node *ptr;
}*start = NULL, *t, *pptr, *last;

struct node *create(struct node *start, int n){
  int i;

  printf("Enter data...\n");
  for(i=0; i<n; i++){
    t = (struct node *)malloc( sizeof(struct node) );
    t->data1=(i+1);
    t->head=2;
    if(start==NULL){
      start = t;
    }
    else{
      last->ptr = t;
    }
    last = t;
  }
  last->ptr = start;
  return start;
}

struct node *display(struct node *start){
  struct node *t1;

  for(t1=start; start!=NULL&&t1->ptr!=start; t1=t1->ptr){
    printf("%d ", t1->data1);
  }
  printf("%d", t1->data1);
  return start;
}

int joseph(struct node *start, int  n){
  int h=2;
  int k;
  int i, j, l;
  struct node *kptr;
  pptr = start;
  printf("\nEnter difference: ");
  scanf("%d", &k);
  for(i=1; i<=(n*(h) - 1); i++){
    for(j=1; j<=k; j++){
      kptr = (pptr->ptr);
      if(kptr->head >1){
        kptr->head--;
      }
      else if(kptr->head == 1){
        kptr->ptr = (kptr->ptr)->ptr;
      }
      pptr = kptr->ptr;
    }
  }
  return (kptr->data1);
}

void main()
{
  int n;
  printf("Enter number of people: ");
  scanf("%d", &n);
  if(n==1){ printf("ERROR!\n"); exit(0);}
  start = create(start, n);
  start = display(start);

  printf("Position %d will be saved!", joseph(start, n));

}
