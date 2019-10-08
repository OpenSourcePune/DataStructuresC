#include<stdio.h>
#include<stdlib.h>

void main()
{
    int a[50], fai, n, ch;
    printf("Enter number of elements you want:\n");
    scanf("%d",&n);
    fai=n-1;
    printf("Enter elements:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    do
    {
        printf("Welcome to array options:\n");
        printf("1.Insertion, 2.Deletion, 3.Sort, 4.Binary Search, 5.Display, 6.Exit\n");
        printf("Enter choice!:\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:{ int pos, ele;
                     printf("Insertion:\n");
                     printf("Enter element and position:\n");
                     scanf("%d%d",&ele,&pos);
                     if(fai<49 && pos>=1 && pos<=fai+2)
                     {
                         for(int z=fai; z>=pos-1;z--)
                         {
                             a[z+1]=a[z];
                         }
                         a[pos-1]=ele;
                         fai++;
                     }
                     else
                        printf("Insertion not possible!");
                     break;
                    }
            case 2:{ int pos;
                      printf("Deletion:\n");
                      printf("Enter position to delete from array\n");
                      scanf("%d",&pos);
                      if(fai!=-1 && pos<=(fai+1) && pos>=1)
                      {

                          for(int x=pos-1;x<fai;x++)
                          {
                              a[x]=a[x+1];
                          }
                          fai--;
                      }
                          else
                            printf("Deletion not possible!");
                          break;
                    }
            case 3:{    printf("Sorting:\n");
                        int temp;
                        for(int i=0;i<=fai;i++)
                        {

                            for (int j=i+1;j<=fai;j++)
                            {

                                if (a[i]>a[j])
                                {
                                    temp=a[i];
                                    a[i]=a[j];
                                    a[j]=temp;
                                }
                            }
                        }
                        break;
                    }
            case 4:{    printf("Binary Search:\n");
                        int v;
                        printf("Enter element to be searched:\n");
                        scanf("%d",&v);
                        int BinarySearch(int b[], int l, int u, int ele)
                        {
                            int x, mid;
                            if(l<=u)
                            {
                                mid=(l+u)/2;
                                if(ele>b[mid])
                                {
                                    l=mid+1;
                                    x=BinarySearch(b,l,u,ele);
                                }
                                else if(ele<b[mid])
                                {
                                    u=mid-1;
                                    x=BinarySearch(b,l,u,ele);
                                }
                                else
                                {
                                return mid;
                                }
                                return x;
                            }
                            return -1;
                        int flag=BinarySearch(a[fai],0,fai,v);
                        if(flag!=-1)
                            printf("Element found!");
                        else
                            printf("Not found!");
                        }
                     break;
            }
            case 5: {   printf("Display:\n");
                        for(int r=0;r<=fai;r++)
                        {
                            printf("%d ",a[r]);
                        }
                        printf("\n");
                        break;
                    }
            case 6: {   printf("Exiting!\n"); exit(4);
                        break;
                    }
            default: {
                        printf("Wrong Input!!!");
                        break;
                     }
        }
    }while(ch>0 && ch<7);
}
