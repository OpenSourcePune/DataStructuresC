#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
char stack[100];

void push(char);
void pop();
void isMatching();

void main(){
  int i;
  char a[100];
  FILE *myFile;
  myFile = fopen("read.c", "r");

for (i = 0; i < 100; i++){
    fscanf(myFile, "%c", &a[i]);
}

	// printf("enter expression\n");
	// scanf("%s", &a);
	for (i = 0; a[i] != '\0';i++)
	{
		if (a[i] == '[')
		{
			push(a[i]);
		}
		else if (a[i] == ']')
		{
			pop();
		}
	}
	isMatching();
}
void push(char a)
{
	stack[top] = a;
	top++;
}
void pop()
{
	if (top == -1)
	{
		printf("Wrong Brackets!\n");
		exit(0);
	}
	else
	{
		top--;
	}
}

void isMatching()
{
	if (top == -1)
		printf("\nNo problems!\n");
	else
		printf("\nWrong Brackets!\n");
}
