#include<iostream>
using namespace std;
void selectionSortMin(int A[] , int n){
	for (int i =0;i< n-1;i++){
		int iMin = i ;
		for(int j = i+1;j<n;j++){
			if(A[j] < A[iMin])
				iMin = j;
		}
		int temp = A[i];
		A[i] = A[iMin];
		A[iMin] = temp;	
	}
}

void selectionSortMax(int A[] , int n){
	for (int r = 0;r<n-1;r++){
		int rMax = r;
		for(int s=r+1;s<n;s++){
			if(A[s] > A[rMax])
				rMax = s;
		}
		int temp1 = A[r];
		A[r] = A[rMax];
		A[rMax] = temp1;
	}
}

int main(){
	int A[] = {2,7,4,1,9,5,3,-4,14,-1};
	int n = sizeof(A)/sizeof(A[0]);
	cout<<"\n"<<"This is for minimum for selection sort algo"<<"\n";
	cout<<"\n";
	selectionSortMin(A,n);
	for (int i = 0 ;i< n ;i++)
		cout<<A[i]<<"\n";
	
	cout<<"\n"<<"This is for maximum for selection sort algo"<<"\n";
	cout<<"\n";
	selectionSortMax(A,n);
	for (int i = 0 ;i< n ;i++)
		cout<<A[i]<<"\n";
}
