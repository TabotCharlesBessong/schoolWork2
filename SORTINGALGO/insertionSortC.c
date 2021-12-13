#include<math.h>
#include<stdio.h>

void insertionSort(int arr[] , int n){
	int i,element,j;
	for(i =1;i<n;i++){
		element = arr[i];
		j = i-1;
		while(j>=0 && arr[j] > element){
			arr[j+1] =arr[i];
			j--;
		}
		arr[j+1] = element;
	}
}

int main(){
	int arr[] = {2,7,34,23,4,1,9,5,3,-4,14,8,-1};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("\nThis is for minimum for insertion sort algo\n");
	printf("\n");
	insertionSortMin(arr,n);
	int i;
	for(i = 0 ;i< n ;i++){
		printf("%d\n",arr[i]);
	}
	
}
