#include <stdio.h>
//Doubly linked lists
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
struct node{
  int rollno;
  char name[15];
  char sec[1];
  struct node *prev,*next;
}*start=NULL,*t,*end,*npr;

void createDLinkedList(int n){
  char dummyname[15];
  char dummysec[1];
  for(int i=0;i<n;i++){
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter rollno at node %d : ",(i+1));
    scanf("%d",&((*t).rollno));
    printf("Enter name at node %d : ",(i+1));
    scanf("%s",dummyname);
    strcpy((*t).name,dummyname);
    printf("Enter sec at node %d : ",(i+1));
    scanf("%s",dummysec);
    strcpy((*t).sec,dummysec);
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
    printf("Roll number : %d\t",t->rollno);
    printf("Name : %s\t",t->name);
    printf("Section : %s\n",t->sec);
  }
  printf("Roll number : %d\t",t->rollno);
  printf("Name : %s\t",t->name);
  printf("Section : %s\n",t->sec);
}

void insertDLinkedList(int pos, int rollno, char name[], char sec[]){
  t = (struct node *)malloc(sizeof(struct node));
  (*t).rollno = rollno;
  strcpy((*t).name,name);
  strcpy((*t).sec,sec);
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

// int linearSearchDLinkedList(int ele){
//   int flag = 0;
//   for(t=start;t->next!=NULL;t=t->next){
//     if(t->data==ele || end->data==ele){
//       flag = 1;
//       break;
//     }
//   }
//   return flag;
// }

// void sortDLinkedList(struct node * start){
//   struct node *i,*j;
//   int temp;
//   for(i=start;i->next!=NULL;i=i->next){
//     for(j=i->next;j!=NULL;j=j->next){
//       if(((*i).data)>((*j).data)){
//         temp = (*i).data;
//         (*i).data = (*j).data;
//         (*j).data = temp;
//       }
//     }
//   }
// }


void main(){
  int i,j,n;
  int pos,rollno;
  char name[15];
  char sec[1];
  int ch;
  do{
    printf("Welcome to doubly linked lists --\n");
    printf("Enter a choice :\n");
    printf("0.Creation 1.Insertion 2.Deletion 3.Display Next 4.Display All 5.Sort 6.Exit:\n");
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
                printf("Enter postion, rollno, name, section : ");
                scanf("%d %d %s %s",&pos,&rollno, name, sec);
                insertDLinkedList(pos,rollno,name,sec);
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
                
                }

      case 4 : {
                printf("Display All:\n");
                displayDLinkedList(start);
                printf("\n");
                break;
                }
      // case 5 : {
      //           printf("Sorting....\n");
      //           sortDLinkedList(start);
      //           printf("Sorted!\n\n");
      //           break;
      //           }
      case 6 : {
                printf("Exiting!");
                exit(0);
                }
      default : printf("This is default\n");
    }
  }while(ch>=0 && ch<7);
}
