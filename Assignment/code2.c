#include<stdio.h>

void sort(int arr[],int low,int mid,int high){
    int i,m,k,l,temp[100];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high)){
        if(arr[l]<=arr[m]){
            temp[i]=arr[l];
            l++;
        }
        else{
            temp[i]=arr[m];
            m++;
        }
        i++;
    }
    if(l>mid){
        for(k=m;k<=high;k++){
            temp[i]=arr[k];
            i++;
        }
    }
    else{
        for(k=l;k<=mid;k++){
            temp[i]=arr[k];
            i++;
        }
    }
    for(k=low;k<=high;k++){
        arr[k]=temp[k];
    }
}

void partition(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        partition(arr,low,mid);
        partition(arr,mid+1,high);
        sort(arr,low,mid,high);
    }
}

void main(){
    int t,n,i;
    printf("Enter Test Cases:\n");
    scanf("%d",&t);
    while(t--){
        printf("Enter Number of Workers:\n");
        scanf("%d",&n);
        int arr[n];
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        partition(arr,0,n-1);
        int s=0,sum=0,p=0;
        for(i=0;i<n-1;i++){
            p=s+(arr[i+1]-arr[i]);
            s=p;
            sum+=p;
        }
        printf("Number of Operations : %d\n",sum);
    }
}
