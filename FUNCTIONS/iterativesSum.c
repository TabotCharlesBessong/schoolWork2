#include<stdio.h>

int sum(int num){
	if(num)
		return (num + sum(num-1));
	else
		return 0;
}
void display(int num){
	if(num){
		display(num - 1);
	}else{
		return ; 
	}
	printf("\n%d",num);
}

int main(){
	int n,b;
	printf("Enter a number of your choice\n: ");
	scanf("%d",&n);
	printf("The sum of numbers from 0 to %d is %d \n",n,sum(n));
	printf("Enter a number of your choice\n: ");
	scanf("%d",&b);
	display(b);
	
	return 0;
}
