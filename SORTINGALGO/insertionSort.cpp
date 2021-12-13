#include<iostream>
using namespace std;

void insertionSortMin(int C[] , int n ){
	for(int i = 0;i<n;i++){
		int value = C[i];
		int hole = i;
		while(hole > 0 && C[hole-1] > value ){
			C[hole] = C[hole-1];
			hole--;
		}
		C[hole] = value;
	}
}

void insertionSortMax(int C[] , int n ){
	for(int i = 0;i<n;i++){
		int value = C[i];
		int hole = i;
		while(hole > 0 && C[hole-1] < value ){
			C[hole] = C[hole-1];
			hole--;
		}
		C[hole] = value;
	}
}

int main(){
	int C[] = {2,7,34,23,4,1,9,5,3,-4,14,8,-1};
	int n = sizeof(C)/sizeof(C[0]);
	cout<<"\n"<<"This is for minimum for insertion sort algo"<<"\n";
	cout<<"\n";
	insertionSortMin(C,n);
	for (int i = 0 ;i< n ;i++)
		cout<<C[i]<<"\n";
		
	cout<<"\n"<<"This is for maximum for insertion sort algo"<<"\n";
	cout<<"\n";
	insertionSortMax(C,n);
	for (int i = 0 ;i< n ;i++)
		cout<<C[i]<<"\n";
}
