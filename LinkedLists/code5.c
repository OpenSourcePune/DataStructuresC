#include <stdio.h>
//Doubly linked lists
#include <stdlib.h>

struct node{
  int data;
  struct node *prev,*next;
}*start=NULL,*t,*end,*npr;

void createDLinkedList(int n){
  for(int i=0;i<n;i++){
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter data at node %d : ",(i+1));
    scanf("%d",&((*t).data));
    t->prev = t->next = NULL;
    if(start==NULL){
      start = t;
      t->prev = start;
    }else{
      end->next = t;
      t->prev = end;
    }
    end = t;
  }
}

void displayDLinkedList(struct node * start){
  for(t=start;t->next!=NULL;t=t->next){
    printf("%d ",t->data);
  }
  printf("%d",t->data);
}

void insertDLinkedList(int pos, int ele){
  t = (struct node *)malloc(sizeof(struct node));
  (*t).data = ele;
  t->next = NULL;
  if(pos==1){
    t->next = start;
    start->prev = t;
    start = t;
  }else{
    npr = start;
    for(int i=2;i<pos&&(npr->next!=start);i++){
      npr = npr->next;
    }
    t->next = npr->next;
    t->prev = npr;
    if(npr->next!=NULL){
      npr->next->prev = t;
    }
      npr->next = t;
  }
}

void deletionDLinkedList(int pos){
  if(pos==1){
    t = start;
    start = t->next;
  }else{
    npr = NULL;
    t = start;
    for(int i=1;i<pos && t->next!=NULL;i++){
      npr = t;
      t = t->next;
    }
    npr->next = t->next;
    t = t->next;
    t->prev = npr;
  }
  free(t);
}

int linearSearchDLinkedList(int ele){
  int flag = 0;
  for(t=start;t->next!=NULL;t=t->next){
    if(t->data==ele || end->data==ele){
      flag = 1;
      break;
    }
  }
  return flag;
}

void sortDLinkedList(struct node * start){
  struct node *i,*j;
  int temp;
  for(i=start;i->next!=NULL;i=i->next){
    for(j=i->next;j!=NULL;j=j->next){
      if(((*i).data)>((*j).data)){
        temp = (*i).data;
        (*i).data = (*j).data;
        (*j).data = temp;
      }
    }
  }
}


void main(){
  int i,j,n;
  int pos,ele;
  // printf("Enter number of nodes in the ll : ");
  // scanf("%d",&n);
  // createLinkedList(n);
  // displayLinkedList(start);
  //
  // printf("\nEnter the position and element to be inserted : ");
  // scanf("%d %d",&pos,&ele);
  // insertLinkedList(pos,ele);
  // n++;
  // displayLinkedList(start);
  int ch;
  do{
    printf("Welcome to doubly linked lists --\n");
    printf("Enter a choice :\n");
    printf("0.Creation 1.Insertion 2.Deletion 3.Linear Search 4.Display 5.Sort 6.Exit:\n");
    scanf("%d",&ch);
    switch(ch){
      case 0 :  {
                printf("Creation :\n");
                printf("Enter number of nodes :\n");
                scanf("%d",&n);
                createDLinkedList(n);
                break;
                }
      case 1 : {
                printf("Insertion:\n");
                printf("Enter postion and element : ");
                scanf("%d %d",&pos,&ele);
                insertDLinkedList(pos,ele);
                n++;
                printf("\n");
                break;
                }
      case 2 : {
                printf("Deletion : ");
                printf("Enter position for deletion : ");
                scanf("%d",&pos);
                deletionDLinkedList(pos);
                n--;
                printf("\n");
                break;
                }
      case 3 : {
                printf("Linear Search :");
                printf("Enter the element value to look for : ");
                scanf("%d",&ele);
                int flag = linearSearchDLinkedList(ele);
                if (flag==1){
                  printf("Element found!");
                }else{
                  printf("Not found");
                }
                printf("\n");
                break;
                }

      case 4 : {
                printf("Display:\n");
                displayDLinkedList(start);
                printf("\n");
                break;
                }
      case 5 : {
                printf("Sorting....\n");
                sortDLinkedList(start);
                printf("Sorted!\n\n");
                break;
                }
      case 6 : {
                printf("Exiting!");
                exit(0);
                }
      default : printf("This is default\n");
    }
  }while(ch>=0 && ch<7);
}
