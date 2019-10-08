#include<stdio.h>

void main(){
	int TestCases,Sum,NumberOfElephants,Candies,k;
    scanf("%d",&TestCases);
	while(TestCases>0){
		scanf("%d %d",&NumberOfElephants,&Candies);
		Sum=0;
		while(NumberOfElephants>0){
			scanf("%d",&k);
			Sum=Sum+k+2;
			NumberOfElephants--;
		}
		if(Candies<Sum)
			printf("No!\n");
		else
			printf("Yes!\n");
		TestCases--;
	}
}
