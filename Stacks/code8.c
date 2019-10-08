#include<stdio.h>
#include<stdlib.h>
int top=-1,size=100;
char p[100],q[100],stack[20];

void push(char ele)
{
    if(top == size-1)
    {
        printf("Overflow");
    }
    else{
    stack[++top] = ele;
    }
}

char pop()
{
    if(top==-1)
        printf("Underflow");
    else
    {
        return stack [top--];
    }
}

void display()
{
        printf("%s",q);

}

int prio(char x)
{
    if(x=='+'||x=='-')
        return 2;
    else if(x=='/'||x=='*')
        return 3;
    else
        return 1;
}

void main()
{
    char sop;
    int i=0,j=0;
    push('#');
    printf("Enter expression : ");
    scanf("%s",&p);

    while(p[i]!='\0')
    {
        if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/')
        {
            sop=pop();
            while(prio(sop)>=prio(p[i]))
            {
                q[j++]=sop;
                sop=pop();
            }
            push(sop);
            push(p[i]);
        }
        else if(p[i]=='(')
            push('(');
        else if(p[i]==')')
        {
            sop=pop();
            while(sop!='(')
            {
                q[j++]=sop;
                sop=pop();
            }
        }
        else
        {
            q[j++] = p[i];
        }
        i++;
    }
    sop=pop();
    while(sop!='#')
    {
        q[j++]=sop;
        sop=pop();
    }
    q[j]='\0';
    display();
}
