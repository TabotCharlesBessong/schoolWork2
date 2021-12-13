//TABOT CHARLES BESSONG
// FE20A106

#include<iostream>
using namespace std;

int binSearch(int arr[] , int l, int r , int x){
	if(r >= 1){
		int mid = 1 + (r - 1) /2;
		if(arr[mid] == x)
			return mid;
		if(arr[mid] > x)
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
	int n= sizeof(arr)/sizeof(arr[0]);
	int result = binSearch(arr,0,n-1,x);
	cout <<"The element "<<x<<"is at index "<<result;
}
