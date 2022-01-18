#include<stdio.h>

// in c , we sometimes or calways aneed to call the function before the main function 
int linearSearch(int A[] , int n , int value);
	int arr[] = {2,6,1,4,-3,5,4};


int main(void){
	int n = sizeof(arr) / sizeof(arr[0]);
	int index = linearSearch(arr,n,4);
	printf("The  number you are looking for is at index %d",index);
	
	return 0;
}

int linearSearch(int A[], int n , int value){
	int i ;
	// so we are simply iterating between the the values until we meet  one that is same  as  our  value we are  looking for 
	for(i=0;i<n;i++){
		if(A[i] == value){
			int j = i;
			return i;
			while(i < n){
				linearSearch(arr,n,4);
			}
		}
	}
	return -1;
}
