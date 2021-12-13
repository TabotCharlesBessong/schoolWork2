#include<stdio.h>

int linearSearch(int A[] , int n , int value);

int main(void){
	int arr[6] = {2,6,1,-3,5,4};
	int index = linearSearch(arr,6,4);
	printf("\n%d",index);
	
	return 0;
}

int linearSearch(int A[], int n , int value){
	int i ;
	for(i=0;i<n;i++){
		if(A[i] == value)
			return i;
	
	}
	return -1;
}
