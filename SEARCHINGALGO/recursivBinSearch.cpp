// TABOT CHARLES BESSONG
// FE20A106

#include<iostream>
using namespace std;

int recursiveBinarySearch(int arr[] , int l , int r, int value){
	if(l <= r){
		int mid = (l + r) /2;
		if(arr[mid] == value)
			return mid;
		if(arr[mid] > value)
			return recursiveBinarySearch(arr , l , mid -1 , value);
		if(arr[mid] < value)
			return recursiveBinarySearch(arr , mid + 1 ,r , value);
	}
	return -1;
}

int main(void) { 
   int arr[] = {1, 3, 7, 15, 18, 20, 25,28, 33, 36, 40,41,67}; 
   int n = sizeof(arr)/ sizeof(arr[0]); 
   int value ; 
   cout <<"Enter the value you are searching";
   cin>>value ;
   int index = recursiveBinarySearch (arr, 0, n-1,value); 
   if(index == -1)
      cout<< value <<" is not present in the array";
   else
      cout<< value <<" is present at index "<< index <<" in the array"; 
   return 0; 
}
