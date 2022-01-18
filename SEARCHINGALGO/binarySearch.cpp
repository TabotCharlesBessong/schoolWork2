//TABOT CHARLES BESSONG
// FE20A106

#include<iostream>
using namespace std;

int binSearch(int arr[] , int l, int r , int x){
	if(r >= 1){
		// if we  have  one or  more element  , we will have to devide and begin to search to either the left side or right side of the array 
		int mid = l + (r - 1) /2;
		if(arr[mid] == x)
		// since we are dividing the array into 2 , if the value is at the middle  , we  return that middle index
			return mid;
		if(arr[mid] > x)
		// to make the search easy for me , i devided the array into 2  , so if the value i am looking for is less than that at the  middle i will seach to the  left and  vice-versa
			return binSearch(arr,l,mid-1,x);
		return binSearch(arr,mid+1,r,x);
	}	
	return -1;
}

int main(){
	int arr[] = {2,4,-2,9,7,3,6,0,-8,5};
	int x = 7;
	
//	cout <<"Enter your number";
//	cin >>x;
  cout << "Hello world"<<endl;
	int n= sizeof(arr)/sizeof(arr[0]);
	int result = binSearch(arr,0,n-1,x);
	cout <<"The element "<<x <<" is at index "<< result;
}
