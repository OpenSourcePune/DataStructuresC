#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *ptr;
}*start=NULL,*t,*end,*npr;

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
  printf("%d",end->data);
}

void insertLinkedList(int pos, int ele){
  t = (struct node *)malloc(sizeof(struct node));
  (*t).data = ele;
  t->ptr = NULL;
  if(pos==1){
    t->ptr = start;
    start = t;
  }else{
    npr = start;
    for(int i=2;i<pos;i++){
      npr = npr->ptr;
    }
    t->ptr = npr->ptr;
    npr->ptr = t;
  }
}

void deletionLinkedList(int pos){
  if(pos==1){
    t = start;
    start = start->ptr;
  }else{
    npr = NULL;
    t = start;
    for(int i=1;i<pos && t->ptr!=NULL;i++){
      npr = t;
      t = t->ptr;
    }
    npr->ptr = t->ptr;
  }
  free(t);
}

int linearSearchLinkedList(int ele){
  int flag = 0;
  for(t=start;t->ptr!=NULL;t=t->ptr){
    if(t->data==ele || end->data==ele){
      flag = 1;
      break;
    }
  }
  return flag;
}

void sortLinkedList(struct node * start){
  struct node *i,*j;
  int temp;
  for(i=start;i->ptr!=NULL;i=i->ptr){
    for(j=i->ptr;j!=NULL;j=j->ptr){
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
    printf("Welcome to linked lists --\n");
    printf("Enter a choice :\n");
    printf("0.Creation 1.Insertion 2.Deletion 3.Linear Search 4.Display 5.Sort 6.Exit:\n");
    scanf("%d",&ch);
    switch(ch){
      case 0 :  {
                printf("Creation :\n");
                printf("Enter number of nodes :\n");
                scanf("%d",&n);
                createLinkedList(n);
                break;
                }
      case 1 : {
                printf("Insertion:\n");
                printf("Enter postion and element : ");
                scanf("%d %d",&pos,&ele);
                insertLinkedList(pos,ele);
                n++;
                printf("\n");
                break;
                }
      case 2 : {
                printf("Deletion : ");
                printf("Enter position for deletion : ");
                scanf("%d",&pos);
                deletionLinkedList(pos);
                n--;
                printf("\n");
                break;
                }
      case 3 : {
                printf("Linear Search :");
                printf("Enter the element value to look for : ");
                scanf("%d",&ele);
                int flag = linearSearchLinkedList(ele);
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
                displayLinkedList(start);
                printf("\n");
                break;
                }
      case 5 : {
                printf("Sorting....\n");
                sortLinkedList(start);
                printf("Sorted!\n\n");
                break;
                }
      case 6 : {
                printf("Exiting!");
                exit(0);
                }
      default : printf("This is default\n");
    }
  }while(ch>=0 && ch<=7);
}
